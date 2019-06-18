# Library

## アルゴリズム

### データ構造

- [UnionFind](https://github.com/Yoshiakira11/Library/blob/master/DataStructure/UnionFind.cpp)
- [RMQ](https://github.com/Yoshiakira11/Library/blob/master/DataStructure/RMQ.cpp)
- [RSQ](https://github.com/Yoshiakira11/Library/blob/master/DataStructure/RSQ.cpp)
- [Treap](https://github.com/Yoshiakira11/Library/blob/master/DataStructure/Treap.cpp)

### 幾何

- [全部](https://github.com/Yoshiakira11/Library/blob/master/Geometry/All.cpp)

### グラフ

- [LowLink]

### 木

### 数学

- [約数列挙](https://github.com/Yoshiakira11/Library/blob/master/Math/Divisor.cpp)
- [冪乗](https://github.com/Yoshiakira11/Library/blob/master/Math/Power.cpp)
- [素因数分解](https://github.com/Yoshiakira11/Library/blob/master/Math/PrimeFactor.cpp)

### 文字列

## その他

- [テンプレート](https://github.com/Yoshiakira11/Library/blob/master/Other/template.cpp)
- [デバッグ](https://github.com/Yoshiakira11/Library/blob/master/Other/debug.cpp)

## コーディング規約の内容φ(..)
取り敢えず、自分がコーディングする際決めてることを書いときます。
それから適宜変えていきましょ。

### 目的
相手のコードを少しでも速く読めるようにするため。

### 命名規則

- 入力

    入力変数の名前は不都合がない限り、問題文と同じにします。
    問題文 : N K a b
    コード : N K a b

- for文

    基本、i, j, k, lの順に使う。
    iが縦、jが横のイメージで。

- 関数

    アルゴリズム名はそのまま。
    Ex: dfs, dijkstra, mst, etc.
    それ以外は動詞を使った名前
    Ex: getHoge, check, isOK, toHoge, calc, solve, etc.

- 出力

    大体、ans, res

- その他
    - bool系: flag, ok, ng, memo, used
    - tmp系: tmp, buff
    - 対称系: left, right, p, q, s, t
    - 位置系: idx, pos
    - 変動する系：t, now, step
    - グラフ系: v(今の頂点), u(行ける頂点）
    - 数える系: cnt, num, match, inc

他にもあるような・・・

### 禁止事項

goto文
一文字を#define
インデントがぐだぐだ

### 制限事項


### 推奨事項


