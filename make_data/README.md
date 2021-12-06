## 脚本使用说明
### 1. 域内异构测试数据生成脚本
异构数据融合的统一管理的测试数据生成程序自动生成由1列数值(numeric(12))和4列字符串(char(8))构成。表结构如下：
```sql
create table table1(id1 numeric(12),id2 char(8),id3 char(8),id4 char(8),id5 char(8));
create table table2(id1 numeric(12),id2 char(8),id3 char(8),id4 char(8),id5 char(8));
```
为便于统计，1000亿行的数据数值列按照顺序累加至千亿(即数值列为1~1000亿)，5000万行的数值按照一定的规则生成。其规则如下：选取1万个数值数据（每隔一千万取一次）使其均匀分布在1000亿数据中，5000万行的数据数值列从一千亿零一按顺序累加至一千亿五千万，每隔5000间隔将之前的1万数据替换进去，使这1万数据也均匀分布在5000万数据中。从而保证与1000亿行的数据关联时有一定数量的查询结果，其余字符串列的内容各不相同。
#### 1.1 1000亿数据生成脚本使用说明
```shell
gcc 1000y.c -o 1000y
./1000y
```
生成的数据会放在当前执行目录下的indomain_data_0.csv~indomain_data_19.csv一共20个文件中，每个文件存放了50亿数据。
#### 1.2 5000万数据生成脚本使用说明
```shell
gcc 5000w.c -o 5000w
./5000w
```
生成的数据会放在当前执行目录下的indomain_data5kw.csv文件中。

### 2. 跨域透明访问测试数据生成脚本
跨域透明访问测试数据的生成程序亦由1列数值(numeric(12))和4列字符串(char(8))构成。其中表tableA的数值列按照顺序累加至1万(即1-10000)，另一张表tableB的数值列由随机数生成器生成100万以内的随机数，这样保证数据关联时有大约100个查询结果。其余字符串列的内容各不相同。表结构如下：
```sql
create table tableA(id1 numeric(12),id2 char(8),id3 char(8),id4 char(8),id5 char(8));
create table tableB(id1 numeric(12),id2 char(8),id3 char(8),id4 char(8),id5 char(8));
```
#### 脚本使用说明
```shell
python tableA.py > crossdomain_data_A.csv
python tableB.py > crossdomain_data_B.csv
```
生成的数据会放在当前执行目录下的crossdomain_data_A.csv和crossdomain_data_B.csv文件中。

