## Problem: 広告ネットワーク

インターネット上で表示されるバナーなどのオンライン広告。そこでは、数百ミリ秒といったとても短い時間で、表示される広告が決定されている。この仕組みを、「SSP」「DSP」「RTB」というキーワードからみていくことにしよう。

SSP は、「Supply-Side Platform（サプライサイドプラットフォーム）」の略である。これはメディア、つまり「広告枠を売りたい側」のシステムである。別の言い方をすれば、広告枠を「供給＝サプライ」する側のプラットフォームということである。例えばあなたが、たくさんのアクセスがあるWebサイトを所有しているとしよう。あなたは、そこに広告バナーの枠を作り、そこに広告を載せる権利を売ることで収入を得ようと考えた。そこであなたは当然「できるだけ高い値段で広告枠を売りたい」と考えることだろう。それを実現するためのシステムが SSP である。

一方 DSP は、「Demand-Side Platform（デマンドサイドプラットフォーム）」の略である。これは広告主、つまり「広告を出したいと思っている側」のシステムである。別の言い方をすれば、広告枠を「要求＝デマンド」する側のプラットフォームということである。例えば、あなたがアプリの製作者であるとしよう。そしてあなたは、アプリを宣伝する広告を出すために、「できるだけ安い値段で、効果的な広告枠を買いたい」と考えたとしよう。それを実現するためのシステムが DSP である。

広告枠がユーザーに表示された時、「広告枠を高い値段で売りたい」SSPと、「広告枠を安く買いたい」DSPとの間で瞬時にオークションが行われ、表示される広告が決定される。この仕組みを 「Real-Time Bidding（リアルタイムビッティング）」、略して RTB という。RTB は、以下のような流れで行われる。

1. ユーザーが広告枠があるページを訪問し、SSPが広告リクエストを受け取る
2. SSPがその広告枠をオークションにかける。すなわち、SSPに接続された複数のDSPに一斉に入札リクエストを送信する
3. 各DSPは、入札するかしないか、入札するとしていくらにするかを決定し、SSPに入札レスポンスを返信する
4. SSPはDSPからのレスポンスのうち、最も入札価格が高いものを選択し、ユーザーに送信する
5. ユーザーに広告が表示される

![RTB模式図](https://www.flywheel.jp/wp/wp-content/uploads/2019/12/rtb_chart2-1024x724.png)

図：RTBの動きの模式図。最も高い５０円をつけたDSPの広告が選ばれている。ただし、実際には入札価格はもっと小さな値である。

DSPは、広告枠やユーザーの情報と表示させたい広告の情報とを照らし合わせることで、入札するかしないか及び入札価格を決定する。簡単な例を挙げれば、同じユーザーに直近に何度も同じ広告を表示してもあまり意味がないことから、回数制限をかけて入札を止めることがある。これをフリークエンシーキャップと呼ぶ。また、入札に勝って広告が表示されたときは「広告枠を購入した」ということであるから、多くの回数広告が表示されて広告枠購入費の累計が予算を超過しそうな場合には、その時点で入札を停止する必要がある。

このように、複数のシステムが複雑に組み合わさってオンライン広告が動作しているが、これを簡略化した上でその動きをシミュレーションすることを考えよう。

まず、ある一つの SSP に対して、DSP が n 個接続されているとする。 各DSPは表示すべき広告を一つだけ持っている。 i番目の DSP が持つ広告の ID を ad<sub class=" typesquare_option">i</sub> としたとき、その広告には固定の入札価格 bid<sub class=" typesquare_option">i</sub>、フリークエンシーキャップ fcap<sub class=" typesquare_option">i</sub> 及び 累計表示回数制限 limit<sub class=" typesquare_option">i</sub> が設定されているとする。SSP は m個の入札リクエストを各 DSP に対して順番に送信する。j番目の入札リクエストは、 広告ターゲットユーザーの固有 ID user<sub class=" typesquare_option">j</sub> 及び最低入札価格 price<sub class=" typesquare_option">j</sub> から構成されている。 i番目のDSPは、以下の条件が全て満たされる時に限り、そのリクエストに対し固定の入札価格 bid<sub class=" typesquare_option">i</sub> を用いて入札するとする。

- 固定の入札価格が、そのリクエストの最低入札価格以上であること。すなわち：  
    最低入札価格 price<sub class=" typesquare_option">j</sub> ≤ 固定の入札価格 bid<sub class=" typesquare_option">i</sub>
- ユーザーに対して、まだ広告を出し過ぎていないこと。すなわち：  
    これまでに ユーザーID user<sub class=" typesquare_option">j</sub> に広告 ad<sub class=" typesquare_option">i</sub> が表示された回数 < フリークエンシーキャップ fcap<sub class=" typesquare_option">i</sub>
- これまでに広告が表示された回数が、累計の表示回数の制限に達していないこと。すなわち：  
    これまでに広告 ad<sub class=" typesquare_option">i</sub> が表示された回数 < 累計表示回数制限 limit<sub class=" typesquare_option">i</sub>

SSP は、入札された広告のうち、最も入札価格が高いものを選択し、その広告がターゲットユーザーに表示されるとする。この動きをシミュレートするプログラムを作成することが、この問題のゴールである。

## Input

入力は複数のデータセットからなる。 各データセットは次の形式で表される。

n m  
ad<sub>1</sub> bid<sub>1</sub> fcap<sub>1</sub> limit<sub>1</sub>  
ad<sub>2</sub> bid<sub>2</sub> fcap<sub>2</sub> limit<sub>2</sub>  
…  
ad<sub>n</sub> bid<sub>n</sub> fcap<sub>n</sub> limit<sub>n</sub>  
user<sub>1</sub> price<sub>1</sub>  
user<sub>2</sub> price<sub>2</sub>  
…  
user<sub>m</sub> price<sub>m</sub>

データセットの最初の行は、二つの整数 n と m からなる。 n はDSP の個数 (1 ≤ n ≤ 20)、 m は入札リクエストの個数 (1 ≤ m ≤ 100) である。

続く n 行のそれぞれには、各 DSP が持つ広告についての情報が与えられる。i行目には、i番目の DSP が持つ広告の情報として、 広告ID ad<sub class=" typesquare_option">i</sub> （アルファベット大文字１文字）、固定の入札価格 bid<sub class=" typesquare_option">i</sub> (整数、1 ≤ bid<sub class=" typesquare_option">i</sub> ≤ 100)、フリークエンシーキャップ fcap<sub class=" typesquare_option">i</sub> (整数、1 ≤ fcap<sub class=" typesquare_option">i</sub> ≤ 100) 及び 累計表示回数制限 limit<sub class=" typesquare_option">i</sub> (整数、1 ≤ limit<sub class=" typesquare_option">i</sub> ≤ 100) が空白区切で与えられる。なお、広告ID ad<sub class=" typesquare_option">i</sub> と入札価格 bid<sub class=" typesquare_option">i</sub> はユニークであることが保証される。

それに続く m 行のそれぞれには、各入札リクエストについての情報が与えられる。j行目には、j番目のリクエストの情報として、ユーザーID user<sub class=" typesquare_option">j</sub> （アルファベット小文字1文字）及び最低入札価格 price<sub class=" typesquare_option">j</sub>（整数、1 ≤ price<sub class=" typesquare_option">j</sub> ≤ 100）が空白区切で与えられる。

入力の終わりは二つのゼロからなる行で表される。データセットの個数は 10 を超えない。

## Output

各データセットについて、与えられた DSP と リクエストから、選択される広告ID を並べた長さ m の文字列を一行に出力せよ。もしあるリクエストで入札が発生しない場合には、広告IDの代わりに “\_” （アンダースコア）を出力せよ。

## Sample Input 1

2 7  
A 20 2 3  
B 10 2 2  
x 10  
x 10  
x 10  
x 30  
y 10  
y 10  
y 10  
1 3  
C 20 2 2  
x 20  
y 20  
z 20  
0 0

## Sample Output 1

AAB\_AB\_  
CC\_

## Sample Input 2

6 11  
O 92 1 2  
P 50 3 5  
R 79 1 1  
T 65 1 4  
U 80 1 3  
Y 100 1 1  
x 79  
x 79  
x 79  
x 79  
x 79  
y 66  
y 66  
y 65  
y 50  
z 51  
z 51  
7 10  
C 40 1 5  
E 10 1 1  
I 67 1 1  
O 39 1 3  
R 22 2 2  
S 52 1 1  
T 1 3 6  
a 1  
a 1  
a 100  
a 1  
a 1  
a 1  
a 1  
a 1  
b 1  
a 1  
0 0

## Sample Output 2

YOUR\_OUTPUT 
IS\_CORRECT