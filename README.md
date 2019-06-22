# Library

ICPC国内予選に向けて事前準備。
[競技ルール](https://icpc.iisf.or.jp/2019-yokohama/2019kokunaiyosen/rules/)

## アルゴリズム

### データ構造

- [UnionFind](https://github.com/Yoshiakira11/Library/blob/master/DataStructure/UnionFind.cpp)
- [Weighted-UnionFind]
- [RMQ](https://github.com/Yoshiakira11/Library/blob/master/DataStructure/RMQ.cpp)
- [RSQ](https://github.com/Yoshiakira11/Library/blob/master/DataStructure/RSQ.cpp)
- [遅延評価セグメント木]
- [Treap](https://github.com/Yoshiakira11/Library/blob/master/DataStructure/Treap.cpp)
- [BIT]

### 幾何

- [全部](https://github.com/Yoshiakira11/Library/blob/master/Geometry/All.cpp)

### グラフ

- [単一始点最短路(Dijkstra)](https://github.com/Yoshiakira11/Library/blob/master/Gragh/Dijkstra.cpp)
- [単一始点最短路(BellmanFord)](https://github.com/Yoshiakira11/Library/blob/master/Gragh/BellmanFord.cpp)
- [最小全域木(Prim)](https://github.com/Yoshiakira11/Library/blob/master/Gragh/MST.cpp)
- [サイクル検出（有向グラフ）]
- [LowLink]
- [二重辺連結成分分解]
- [トポロジカルソート](https://github.com/Yoshiakira11/Library/blob/master/Gragh/TopologicalSort.cpp)
- [最大流]
- [２部マッチング]

### 木

- [木の直径]
- [木の重心]

### 数学

- [約数列挙](https://github.com/Yoshiakira11/Library/blob/master/Math/Divisor.cpp)
- [冪乗](https://github.com/Yoshiakira11/Library/blob/master/Math/Power.cpp)
- [素因数分解](https://github.com/Yoshiakira11/Library/blob/master/Math/PrimeFactor.cpp)
- [二項係数](https://github.com/Yoshiakira11/Library/blob/master/Math/Combination.cpp)
- [逆元](https://github.com/Yoshiakira11/Library/blob/master/Math/mod_inv.cpp)
- [重複組合わせ]
- [最小公倍数]

### 文字列

- [ローリングハッシュ]
- [Suffix Array]
- [最長共通接頭辞]

### その他

- [転倒数]
- [最長増加部分列]
- [最長共通部分列]
- [編集距離]
- [next_combination](https://github.com/Yoshiakira11/Library/blob/master/Math/next_combination.cpp)

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
    - 数える系: cnt, num, match, inc, total, sum

### 禁止事項

goto文

一文字を#define

インデントがばらばら

### 制限事項

これから

### 推奨事項

これから


