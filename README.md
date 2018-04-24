# luaのお勉強

## 内容

### hello
- 標準出力やライブラリ、関数を使った簡単なスクリプト
- デーモン小暮閣下の年齢を表示する

```sh
$ cd hello/kogure.lua
Daemon Kogure is 100055 years old!
```

### print_table
- コマンドライン引数の取得、解析を行うスクリプト
- 2つの数値M,Nを引数として取得し、MxNのかけ算表を表示する
- もし引数を与えない場合は9x9の表を表示する

```sh
$ lua print_table/print99.lua 5 5
  1  2  3  4  5
  2  4  6  8 10
  3  6  9 12 15
  4  8 12 16 20
  5 10 15 20 25

$ lua print_table/print99.lua
  1  2  3  4  5  6  7  8  9
  2  4  6  8 10 12 14 16 18
  3  6  9 12 15 18 21 24 27
  4  8 12 16 20 24 28 32 36
  5 10 15 20 25 30 35 40 45
  6 12 18 24 30 36 42 48 54
  7 14 21 28 35 42 49 56 63
  8 16 24 32 40 48 56 64 72
  9 18 27 36 45 54 63 72 81
```

### c_stack
- CからLuaスタックを使用する簡単なスクリプト
- LuaスタックはCとLuaの間でやり取りを行うための中継データ
- makeを実行して生成された`cstack`を実行する
- 生成された実行ファイルを削除するには`make clean`、オブジェクトファイルもろとも削除するには`make dist_clean`を用いる

```sh
$ cd c_stack/
$ make
gcc -Wall -c main.c
gcc -Wall -c dump_stack.c
gcc -o cstack -llua main.o dump_stack.o
$ ./cstack
Watch inside lua stack...

(1) Push bool true
Stack[ 1] type:boolean, value:TRUE

(2) Push float 10.5
Stack[ 2] type:number, value:10.500000
Stack[ 1] type:boolean, value:TRUE

(3) Push int 3
Stack[ 3] type:number, value:3.000000
Stack[ 2] type:number, value:10.500000
Stack[ 1] type:boolean, value:TRUE
```

### c_callscript1
- CからLuaスクリプトで定義された値を取得、使用する
- makeを実行して生成された`call-lua`を実行する

```sh
$ cd c_callscript1/
$ make
gcc -Wall -c main.c
gcc -o call-lua -llua main.o
$ ./call-lua
NAME: もょもと
LEVEL: 48
HP: 229
ATTACK: 155
SWIFT: 130
EXP: 942197
LOCATION: ローレシア
```

### c_callscript2
- CからLuaスクリプト`add.lua`で定義された関数を呼び出す
- makeを実行して生成された`call-lua`を実行する

```lua
--- add.lua
function add(x, y)
        print("(lua) Received x: " .. x .. ", y: " .. y .. " from C.")
        return x + y
end
```

```sh
$ cd c_callscript2
$ make
gcc -Wall -c main.c
gcc -o call-lua -llua main.o
$ ./call-lua
(lua) Received x: 10.0, y: 5.0 from C.
(C) result: x + y = 15
```
