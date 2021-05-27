
SQL> create table num(regno number(4),c1 number(4), c2 number(4));

Table created.

SQL> insert into num values(&regno, &c1, &c2);
Enter value for regno: 1
Enter value for c1: 12
Enter value for c2: 28
old   1: insert into num values(&regno, &c1, &c2)
new   1: insert into num values(1, 12, 28)

1 row created.

SQL> /
Enter value for regno: 2
Enter value for c1: 44
Enter value for c2: 90
old   1: insert into num values(&regno, &c1, &c2)
new   1: insert into num values(2, 44, 90)

1 row created.

SQL> 3
SP2-0226: Invalid line number
SQL> /
Enter value for regno: 3
Enter value for c1: -12
Enter value for c2: 333
old   1: insert into num values(&regno, &c1, &c2)
new   1: insert into num values(3, -12, 333)

1 row created.

SQL> /
Enter value for regno: 4
Enter value for c1: -543
Enter value for c2: 211
old   1: insert into num values(&regno, &c1, &c2)
new   1: insert into num values(4, -543, 211)

1 row created.

SQL> /
Enter value for regno: 5
Enter value for c1: 1
Enter value for c2: -87
old   1: insert into num values(&regno, &c1, &c2)
new   1: insert into num values(5, 1, -87)

1 row created.

SQL> /
Enter value for regno: 6
Enter value for c1: 0
Enter value for c2: 1221
old   1: insert into num values(&regno, &c1, &c2)
new   1: insert into num values(6, 0, 1221)

1 row created.

SQL> select c1+c2 add, c1-c2 sub, c1*c2 mul, c1/c2 div from num;
select c1+c2 add, c1-c2 sub, c1*c2 mul, c1/c2 div from num
             *
ERROR at line 1:
ORA-00923: FROM keyword not found where expected


SQL> select c1+c2 adn, c1-c2 sub, c1*c2 mul, c1/c2 div from num;

       ADN        SUB        MUL        DIV
---------- ---------- ---------- ----------
        40        -16        336 .428571429
       134        -46       3960 .488888889
       321       -345      -3996 -.03603604
      -332       -754    -114573 -2.5734597
       -86         88        -87 -.01149425
      1221      -1221          0          0

6 rows selected.

SQL> alter table num add total number(6);

Table altered.

SQL> update num set total = c1+c2 where regno = &regno;
Enter value for regno: 1
old   1: update num set total = c1+c2 where regno = &regno
new   1: update num set total = c1+c2 where regno = 1

1 row updated.

SQL> /
Enter value for regno: 2
old   1: update num set total = c1+c2 where regno = &regno
new   1: update num set total = c1+c2 where regno = 2

1 row updated.

SQL> /
Enter value for regno: 3
old   1: update num set total = c1+c2 where regno = &regno
new   1: update num set total = c1+c2 where regno = 3

1 row updated.

SQL> /
Enter value for regno: 4
old   1: update num set total = c1+c2 where regno = &regno
new   1: update num set total = c1+c2 where regno = 4

1 row updated.

SQL> /
Enter value for regno: 5
old   1: update num set total = c1+c2 where regno = &regno
new   1: update num set total = c1+c2 where regno = 5

1 row updated.

SQL> /
Enter value for regno: 6
old   1: update num set total = c1+c2 where regno = &regno
new   1: update num set total = c1+c2 where regno = 6

1 row updated.

SQL> /
Enter value for regno: 7
old   1: update num set total = c1+c2 where regno = &regno
new   1: update num set total = c1+c2 where regno = 7

0 rows updated.

SQL> select * from num where c1 = 0 and total > 0;

     REGNO         C1         C2      TOTAL
---------- ---------- ---------- ----------
         6          0       1221       1221

SQL> select * from table where regno = 4 or total < 0;
select * from table where regno = 4 or total < 0
                    *
ERROR at line 1:
ORA-00906: missing left parenthesis


SQL> select * from num where regno = 4 or total < 0;

     REGNO         C1         C2      TOTAL
---------- ---------- ---------- ----------
         4       -543        211       -332
         5          1        -87        -86

SQL> select * from table where c1<=0 or c2>500;
select * from table where c1<=0 or c2>500
                    *
ERROR at line 1:
ORA-00906: missing left parenthesis


SQL> select * from num where c1<=0 or c2>500;

     REGNO         C1         C2      TOTAL
---------- ---------- ---------- ----------
         3        -12        333        321
         4       -543        211       -332
         6          0       1221       1221

SQL> select * from num where regno != 2 or 3;
select * from num where regno != 2 or 3
                                      *
ERROR at line 1:
ORA-00920: invalid relational operator


SQL> select * from num where regno != 2 or regno != 3;

     REGNO         C1         C2      TOTAL
---------- ---------- ---------- ----------
         1         12         28         40
         2         44         90        134
         3        -12        333        321
         4       -543        211       -332
         5          1        -87        -86
         6          0       1221       1221

6 rows selected.

SQL> select * from num where regno != 2 and regno != 3;

     REGNO         C1         C2      TOTAL
---------- ---------- ---------- ----------
         1         12         28         40
         4       -543        211       -332
         5          1        -87        -86
         6          0       1221       1221

SQL> select * from num where total between 0 and 100;

     REGNO         C1         C2      TOTAL
---------- ---------- ---------- ----------
         1         12         28         40

SQL> select * from num where total not between 0 and 200;

     REGNO         C1         C2      TOTAL
---------- ---------- ---------- ----------
         3        -12        333        321
         4       -543        211       -332
         5          1        -87        -86
         6          0       1221       1221

SQL> select * from num where total in(321,-332,567);

     REGNO         C1         C2      TOTAL
---------- ---------- ---------- ----------
         3        -12        333        321
         4       -543        211       -332

SQL> select * from num where total not in(3211,-332,1221,444);

     REGNO         C1         C2      TOTAL
---------- ---------- ---------- ----------
         1         12         28         40
         2         44         90        134
         3        -12        333        321
         5          1        -87        -86

SQL> create table reg(app_no number(5), name varchar2(10));

Table created.

SQL> insert into reg values(&app_no, '&name');
Enter value for app_no: 1000
Enter value for name: ranvijay
old   1: insert into reg values(&app_no, '&name')
new   1: insert into reg values(1000, 'ranvijay')

1 row created.

SQL> /
Enter value for app_no: 1003
Enter value for name: Jagruti
old   1: insert into reg values(&app_no, '&name')
new   1: insert into reg values(1003, 'Jagruti')

1 row created.

SQL> /
Enter value for app_no: 1445
Enter value for name: Avani
old   1: insert into reg values(&app_no, '&name')
new   1: insert into reg values(1445, 'Avani')

1 row created.

SQL> /
Enter value for app_no: 1398
Enter value for name: Amy
old   1: insert into reg values(&app_no, '&name')
new   1: insert into reg values(1398, 'Amy')

1 row created.

SQL> /
Enter value for app_no: 1576
Enter value for name: katarina
old   1: insert into reg values(&app_no, '&name')
new   1: insert into reg values(1576, 'katarina')

1 row created.

SQL> /
Enter value for app_no: 0977
Enter value for name: swara
old   1: insert into reg values(&app_no, '&name')
new   1: insert into reg values(0977, 'swara')

1 row created.

SQL> /
Enter value for app_no: 4567
Enter value for name: sahil
old   1: insert into reg values(&app_no, '&name')
new   1: insert into reg values(4567, 'sahil')

1 row created.

SQL> /
Enter value for app_no: 8009
Enter value for name: vadim
old   1: insert into reg values(&app_no, '&name')
new   1: insert into reg values(8009, 'vadim')

1 row created.

SQL> /
Enter value for app_no: 4687
Enter value for name: vinay
old   1: insert into reg values(&app_no, '&name')
new   1: insert into reg values(4687, 'vinay')

1 row created.

SQL> select * from reg;

    APP_NO NAME
---------- ----------
      1000 ranvijay
      1003 Jagruti
      1445 Avani
      1398 Amy
      1576 katarina
       977 swara
      4567 sahil
      8009 vadim
      4687 vinay

9 rows selected.

SQL> select * from reg where name like ('v%');

    APP_NO NAME
---------- ----------
      8009 vadim
      4687 vinay

SQL> select * from reg where name like ('%y');

    APP_NO NAME
---------- ----------
      1000 ranvijay
      1398 Amy
      4687 vinay

SQL> select * from reg where name like ('j%i');

no rows selected

SQL> select * from reg where name like ('J%i');

    APP_NO NAME
---------- ----------
      1003 Jagruti

SQL> select * from reg where name like ('A%');

    APP_NO NAME
---------- ----------
      1445 Avani
      1398 Amy

SQL> select * from reg where name like ('_____');

    APP_NO NAME
---------- ----------
      1445 Avani
       977 swara
      4567 sahil
      8009 vadim
      4687 vinay

SQL> select * from reg where name not like ('_____');

    APP_NO NAME
---------- ----------
      1000 ranvijay
      1003 Jagruti
      1398 Amy
      1576 katarina

SQL> select * from reg where name like ('___i%');

    APP_NO NAME
---------- ----------
      4567 sahil
      8009 vadim

SQL> select * from reg where name like ('_a%');

    APP_NO NAME
---------- ----------
      1000 ranvijay
      1003 Jagruti
      1576 katarina
      4567 sahil
      8009 vadim

SQL>