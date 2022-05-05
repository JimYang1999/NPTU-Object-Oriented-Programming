本題接續作業"Student"，為實習生建立新的類別。請完成以下要求：
1. 設計一個c++的類別名為InternStudent，並定義於InternStudent.h，其member function的實作則撰寫於InternStudent.cpp，包含有以下的data members:
  - 姓名(字串，長度含\0不超過20個字)
  - 學號(字串，10碼)
  - 實習成績(浮點數)
  - 學期成績(浮點數，請記得在Student類別中加入此資料成員)
  - 期中考成績(浮點數，-1表示缺考)
  - 期末考成績(浮點數，-1表示缺考)
  - 為簡化程式設計起見，請讓InternStudent類別繼承自作業4所完成的Student類別，並重載（覆載）繼承自Student類別的calculateScore() member function，實習學生的學期成績計算標準如下:
    - 實習成績與期中、期末及學期成績最低均為0分。
    - 學期成績＝實習成績\*0.4 + 期中考\*0.3 + 期末考\*0.3
2. 請修改原本設計好的score.cpp程式，在執行時使用「<」將測試檔「/home/stu/public/cpp2022/hw5/cpp2022intern.dat」導入10位學生的資料
3. 依據所取得的資料，動態建立對應的Student類別與InternStudent類別的物件，請儲存在陣列中（可假設學生人數為10人）
4. 請依學期成績由高而低輸出學生的姓名、學號與學期成績
5. 你可以視需要設計其它的data members或member functions
6. 你必須提供Makefile，並將所有需要的檔案都上傳
7. 程式執行結果參考
```
[22:10 cbf107020@ws hw5]$ ./a.out <cpp2022intern.dat
Yu-Liang Chang (1044180028) 94.24
Jun Wu (1044180000) 92.7
I-ping Li (1044180029) 92
Shou-Liang Sun (1044180004) 86
Shiu-Jia Hong (1044181234) 84.6
Jian-Fu Li (1044180005) 79
Chen-Yuan Huang (1044180025) 76.11
Tommy Wu (1044180033) 75
Yu-Chen Wang (1044180020) 70.7
Amy Chang (1044180011) 19
```
