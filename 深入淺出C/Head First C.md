# 深入淺出C
![Head First C](https://im2.book.com.tw/image/getImage?i=https://www.books.com.tw/img/001/056/40/0010564017.jpg&v=50893552&w=348&h=348)

## 前幾章一些值得注意的小細節

* `&&`表示「並且假如成功的話，就進行⋯⋯」

	```bash
	$ gcc zork.c -o zork && ./zork
	```  
* `break`**不能**用來中斷`if`陳述式  
	誤用`break`去中斷`if`的後果可以看[這裡](http://users.csc.calpoly.edu/~jdalbey/SWE/Papers/att_collapse.html)（The 1990 AT&T Long Distance Network Collapse）

* 串接指定  
	`x = 4`運算式本身也具有回傳值`4`  
	`y = x = 4;`把`x`和`y`都設定成`4`

* 陣列變數當作指標使用  
	`doses[3] == *(doses + 3) == *(3 + doses) == 3[doses]`

* 字串實字（String literals）**永遠不能**被更新  
	* 指向字串實字的變數**不能**用來改變該字串的內容  

		```c
		char *cards = "JQK";
		cards[2] = 'R'; // 不合法！！
		```		
	* 如果從字串實字重新建立一個陣列，就**「能夠」**修改該陣列  

		```c
		char card[] = "JQK";
		card[2] = 'R'; // 合法！！
		```

* 記憶體存儲器（位址由高至低）

	名稱               |用途
	-------------------|-----------------------
	Stack（堆疊）       | 區域變數（local variables）
	Heap（堆積）        | 動態記憶體（dynamic memory）
	Globals（全域區段）  | 全域變數（global variables）
	Constants（常數區段）| 唯讀
	Code（程式碼區段）   | 唯讀

* 指標構成的陣列

	```c
	char* name_for_dog[] = {"Bowser", "Bonza", "Snodgrass"};
	```
	每個**字串實字**都會有一個**指標**指向他

* `|` 符號（管線）是將一個行程之標準輸出連結到另一個行程之標準輸入的符號

	```bash
	$ (./bermuda | ./geo2json) < spooky.csv > output.json
	```

* 命令列選項（command-line option）  
	內容待補（P.149）

* `struct`指標表示法（`t`是指向`struct`的指標）  
	`(*t).age`、`t->age`  
	這兩個表達式表達同一件事

* `strdup()` 函式能夠在 ***heap*** 某處重新產生該字串的完整副本

	```c
	char *copy = strdup(s);
	```
	`strdup()`在`string.h`中，函式計算該字串多長，然後呼叫`malloc()`函式，在 ***heap*** 上配置正確數量的字元

## 第七章、函式進階
* 指向函式的指標  
	用法是 `回傳類型(*指標變數)(參數型別)`  
	像這樣 `char** (*names_fn)(char*, int)`

	舉個小小的例子

	```c
	int (*wrap_fn)(int);
	wrap_fn = go_to_wrap_speed; 	//儲存go_to_wrap_speed()函式的位址
	wrap_fn(4); 					//這就跟呼叫go_to_wrap_speed(4)函式一樣
	```

* 排序函式（sort function）與比較器函式（comparator function）  
	在`stdlib.h`裡面有一個`qsort()`函式，看起來長這樣

	```c
	qsort(void array, 									//指向陣列的指標
		  size_t length, 								//該陣列的長度
		  size_t item_size, 							//陣列裡每個元素的尺寸
		  int (*compar)(const void *, const void *)); 	//指向比較陣列裡頭兩個項目的函式
	```
	示範的程式放在資料夾 qsort\_with\_comparator 裡面

* 函式指標陣列  
	用法是`回傳類型(*指標變數[])(參數型別)`  

	```c
	void (*replies[])(response) = {dump, second_chance, marriage}; //陣列裡面存放指向函式的指標
	```
	範例程式在 mail_merge 裡面

* 可變參數函式（Variadic function）  
	直接來個範例：

	```c
	#include <stdarg.h> //處理可變參數函式的程式碼都在這

	void print_ints(int args, ...) {					//「...」被稱作「省略」（ellipsis），告訴你後面還有東西
		va_list ap; 									//va_list 用來儲存要傳進你的函式的額外引數
		va_start(ap, args); 							//va_start 指名可變動引數從哪裡開始
		for(int i = 0; i < args; i++)
			printf("argument: %d\n", va_arg(ap, int)); 	//va_arg 接受兩個值：va_list 和下一個引數的「型別」
		va_end(ap); 									//讀完之後記得要結束
	}

	//call the function
	print_ints(3, 79, 101, 32);
	print_ints(2, 10, 2);
	```

	* 小提示  

		1. `va_end`、`va_start` 等東西實際上是**巨集**，不是函式  
		2. 至少要有**一個**固定參數  
		3. 如果嘗試讀取比傳進來的還要多的引數，會發生隨機錯誤（random error）

## 第八章、動態與靜態程式庫

* 使用`-I`選項來告訴編譯器去哪找標頭檔

	```zsh
	$ gcc -I/my_header_files test_code.c ... -o test_code
	```
	這樣就可以直接用 `#include<some_header.h>` 了（尖括號）

* 收藏檔五四三  
	* 收藏檔包含`.o`目的檔  
	* 用`nm`指令檢視收藏檔的內容  

		```bash
		$ nm libl.a
		```
	* 使用`ar`命令建立收藏檔  

		```bash
		$ ar -rcs libhfsecutity.a encrypt.o checksum.o
		```

		1. `r`表示如果`.a`檔已經存在則更新
		2.	`c`表示建立收藏檔而沒有回饋訊息
		3.	`s`叫`ar`指令在`.a`檔案開頭處建立索引（index）
		4.	收藏檔總是該命名為`lib<something>.a`
	* 編譯

		```bash
		$ gcc test_code.c -lhfsecutity -o test_code
		```
		`hfsecutity`叫編譯器尋找名為`libhfsecutity.a`的收藏檔  
		如果收藏檔放在其他地方，用`-L`選項指名要搜尋哪些目錄

		```bash
		$ gcc test_code.c -L/my_lib -lhfsecutity -o test_code
		```
		`-L`旗標應該出現在`gcc`指令裡頭的原始碼檔案之後

* 動態程式庫  
	動態程式庫在**執行時期**（runtime）才被連結到程式  
	* 在不同的作業系統上有不同的名稱

		1. `hfcal.dll`（Windows 上的 MinGW）
		2. `libhfcal.dll.a`（Windows 上的 Cygwin）
		3. `libhfcal.so`（Linux 或 Unix）
		4. `libhfcal.dylib`（Mac）  

		備註：Linux 或 Unix 上的`so`代表**共用目的檔**（shared object file），Mac 上的`dylib`代表**動態程式庫**（dynamic library）  
	* 用`-shared`旗標建立動態程式庫
		
		```bash
		$ gcc -shared hfcal.o -o /libs/libhfcal.dylib
		```

	靜態與動態程式庫的範例分別在 static-library 跟 dynamic-library 裡面
	
## 第九章、行程與系統呼叫

* `system()`函式  
	`system()`函式接受單一參數並執行，就像直接在命令列上輸入一樣，簡單又方便  
	
	```c
	system("ls -l");
	```

	但是`system()`函式並不安全，有可能被**住入**（inject）程式碼片段，範例在 unsafe\_system_call 裡面  
	這個範例還有其他可能遇到的問題，詳情請洽第 403 頁

* `exec()`函式
	`exec()`函式透過執行某個程式來**替換當前的行程**  
	行程就是**在記憶體裡執行的程式**，作業系統用**行程識別符**（process identifier，PID）來追蹤每個行程

	`exec()`函式有很多不同版本，主要分成兩群，串列（list）函式跟陣列（array）函式
	
	* 串列（list）函式，接受參數串列的命令列引數：  
		* execl()  
		* execlp()：根據路徑（PATH）搜尋程式  
		* execle()：使用環境陣列的字串
	* 陣列（array）函式，如果命令列引數已經先存在串列裡面的話：  
		* execv()  
		* execvp()：根據路徑（PATH）搜尋程式  
		* execve()：使用環境陣列的字串  
		
	看出規則了吧～～

	範例在這，假如有一個檔案`dinner_info.c`，內容如下：

	```c
	#include <stdio.h>
	#include <stdlib.h>

	int main(int argc, char *argv[]) {
		printf("Dinners: %s\n", argv[1]);
		printf("Juice: %s\n", getenv("JUICE")); //stdlib.h 裡的 getenv() 讓你讀取環境變數
		return 0;
	}
	```
	然後你執行：
	
	```c
	//陣列的最後一個項目必須是 NULL
	char *my_env[] = {"JUICE=peach and apple", NULL};
	
	//這裡需要 NULL 告訴函式沒有其他引數了
	execle("dinner_info", "dinner_info", "4", NULL, my_env);
	```
	結果會長這樣：
	
	```
	Dinners: 4
	Juice: peach and apple
	```

* 系統呼叫的錯誤處理  
	檢查錯誤的方法有很多：
	  
	1. 如果`exec()`呼叫成功，當前程式便會**停止執行**，因此，假如程式在呼叫`exec()`之後還在執行任何工作，那一定是有問題
	2. 也可以檢查`exec()`函式是否回傳`-1`
	3. 但這邊要介紹的是`errno`變數
	
		`errno`變數是儲存在`errno.h`裡的**全域變數**，有一連串標準錯誤值：
		
		* `EPERM=1` Operation not permitted
		* `ENOENT=2` No such file or directory
		* `ESRCH=3` No such process  
		* 還有另外一百多種錯誤，詳情可參見[維基百科](https://zh.wikipedia.org/wiki/Errno.h)
		
		因為`errno`變數實際上只是數字，可以使用`string.h`裡的`strerror()`函式查詢標準錯誤訊息（就是那個數字代表的含意）：  
		
		```c
		puts(strerror(errno));	//將錯誤數字轉換為錯誤訊息
		```

	相關的範例放在 exec\_error_handle 裡面

* `fork()`函式  
	`fork()`函式會複製你的行程，為當前行程產生完整**副本**  
	原先的行程被稱作**父行程**，新建立的副本叫做**子行程**

	呼叫`fork()`的方法：
	
	```c
	pid_t pid = fork();
	```
	`pid_t`的型態取決於作業系統，有些使用`short`，有些可能使用`int`  
	`fork()`回傳`0`的整數值給子行程，回傳**正的整數值**給父行程，父行程會收到子行程的行程識別符（PID）

	範例（在 rssgossip 裡的 newshound.c）：用`exec()`呼叫 Python 程式讀取 RSS 檔案

* 小整理  
	1. `system()`像控制台命令那樣執行字串
	2. `fork()`複製當前行程
	3. `fork()`+`exec()`建立子行程
