# TouchGfxMineSweeper



■ 一つ目のブロック
 * [ ] 真ん中のボタンを押す
 * [ ] 真ん中は何も書かれない状態で開く

■ 9つの目のブロック
 * [ ] 真ん中のボタンを押す
 * [ ] 真ん中は何も書かれない状態で開く
 * [ ] 上のブロックと下のブロックが開いて、青色で1と書かれているものが表示される
 * [ ] 左と右のブロックが開いて、緑色で2と書かれているものが表示される
 * [ ] 四隅のブロックは何も変化しない

■ 爆弾がありそうなところに旗を立てる
 * [ ] 右側の空きスペースにトグルの旗ボタンを用意する
 * [ ] 押すと旗ボタンに切り替わる
 * [ ] 旗ボタンを押している状態で右上のブロックに触ると旗がたつ
 * [ ] 旗ボタンを押している状態で、右上の旗が立っているブロックに触ると旗がおちるa
 * [ ] 旗ボタンを押していない状態で右上のブロックに触ると何も起きない

■ 爆弾
 * [ ] 旗ボタンを押していない状態で右上のブロックに触ると爆弾が出る

■ もっとも小さなゲーム
 * [ ] 最初のブロックを押すと以下の処理がはしる(model)
   * [ ] 3x3のマスのどこかに箇所に爆弾を埋め込む、ただしプレイヤーが最初に押した箇所は爆弾を配置しない
   * [ ] 配置された爆弾の位置から、周りにある爆弾の数を計測する
   * [ ] プレイヤーが押した箇所のブロックの状態をオープンにする
   * [ ] オープンかつ0の場所の周囲は爆弾がないことが自明なので、オープンにする。これを繰り返す。0の周りにクローズ状態のものがなくなったら処理終了
 * [ ] 上記のブロック情報に従って、ブロックを適切な状態にする
 * [ ] 上記を繰り返して
   * [ ] 爆弾を開いてしまったら失敗終了
   * [ ] 爆弾以外をすべて開いたら成功終了


■ゴール
1. マインスイーパーができる
   * ブロックが表示される
   * ブロックを押すとブロックがあけれる
   * UIでフラグがたてれる
2. IOでフラグタテができる
3. ボックスを作る
4. 爆弾を激しめに爆発するアイデア
