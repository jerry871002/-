#深入淺出C
![Head First C](https://im2.book.com.tw/image/getImage?i=https://www.books.com.tw/img/001/056/40/0010564017.jpg&v=50893552&w=348&h=348)

##前幾章一些值得注意的小細節

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
		
##第七章、函式進階
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

##第八章、動態與靜態程式庫

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
	在不同的作業系統上有不同的名稱
	
	1. hfcal.dll（Windows 上的 MinGW）
	2. libhfcal.dll.a（Windows 上的 Cygwin）
	3. libhfcal.so（Linux 或 Unix）
	4. libhfcal.dylib（Mac）  
	
	備註：Linux 或 Unix 上的 so 代表共用目的檔（shared object file），Mac 上的 dylib 代表動態程式庫（dynamic library）
	用 -shared 旗標
		gcc -shared hfcal.o -o /libs/libhfcal.dylib

靜態與動態程式庫的範例在 static-library 跟 dynamic-library 裡面

