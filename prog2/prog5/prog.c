#include <stdio.h>

//構造体の型宣言
struct OLD
{
  int no;        //番号
  char *name;    //名前
  int s_year;    //年
  char s_class;  //クラス
};

int main()
{
  int i = 0;
  printf("学籍番号\t 名前\t学年\tクラス\n");

  //構造体の初期化
  struct OLD old[15] =
    {
      { 1,"上杉謙信"    ,3,'A'},
      { 2,"武田信玄"    ,3,'A'},
      { 3,"豊臣秀吉"    ,3,'A'},
      { 4,"明智光秀"    ,3,'A'},
      { 5,"織田信長"    ,3,'A'},
      { 6,"徳川家康"    ,3,'A'},
      { 7,"聖徳太子"    ,3,'A'},
      { 8,"マッカーサー",3,'A'},
      { 9,"ザビエル"    ,3,'A'},
      {10,"北条政子"    ,3,'A'},
      {11,"沖田総司"    ,3,'A'},
      {12,"永倉新八"    ,3,'A'},
      {13,"斉藤一"      ,3,'A'},
      {14,"松原忠治"    ,3,'A'},
      {15,"武田観柳斎"  ,3,'A'},
    };

  for(i = 0; i < 15; i++) {
    //結果の出力
    printf("%7d%15s%5d%10c\n", old[i].no, old[i].name, old[i].s_year, old[i].s_class);
  }
  return 0;
}
