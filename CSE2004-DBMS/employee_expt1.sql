
SQL*Plus: Release 11.2.0.2.0 Production on Fri Jul 24 10:47:16 2020

Copyright (c) 1982, 2014, Oracle.  All rights reserved.

SQL> connect
Enter user-name: system
Enter password:
Connected.
SQL> create table emp(id number(3), salary number(10), name varchar2(30), dob date, address varchar2(20));

Table created.

SQL> insert into emp values(3,6000,'shiva',12-june-1998,'Vellore');
insert into emp values(3,6000,'shiva',12-june-1998,'Vellore')
                                         *
ERROR at line 1:
ORA-00984: column not allowed here


SQL>  insert into emp values(3,6000,'shiva','12-june-1998','Vellore');

1 row created.

SQL> insert into emp values(&id, &salary, '&name', '&dob','&address');
Enter value for id: 1
Enter value for salary: 2000
Enter value for name: ana
Enter value for dob: 13-oct-2000
Enter value for address: Pune
old   1: insert into emp values(&id, &salary, '&name', '&dob','&address')
new   1: insert into emp values(1, 2000, 'ana', '13-oct-2000','Pune')

1 row created.

SQL> /
Enter value for id: 2
Enter value for salary: 3000
Enter value for name: swara
Enter value for dob: 26-jun-2002
Enter value for address: Pune
old   1: insert into emp values(&id, &salary, '&name', '&dob','&address')
new   1: insert into emp values(2, 3000, 'swara', '26-jun-2002','Pune')

1 row created.

SQL> /
Enter value for id: 4
Enter value for salary: 5000
Enter value for name: rajni
Enter value for dob: 03-aug-1999
Enter value for address: Chennai
old   1: insert into emp values(&id, &salary, '&name', '&dob','&address')
new   1: insert into emp values(4, 5000, 'rajni', '03-aug-1999','Chennai')

1 row created.

SQL> /
Enter value for id: 5
Enter value for salary: 7000
Enter value for name: rani
Enter value for dob: 23-dec-2000
Enter value for address: Kolkata
old   1: insert into emp values(&id, &salary, '&name', '&dob','&address')
new   1: insert into emp values(5, 7000, 'rani', '23-dec-2000','Kolkata')

1 row created.

SQL> select * from emp;

        ID     SALARY NAME                           DOB
---------- ---------- ------------------------------ ---------
ADDRESS
--------------------
         3       6000 shiva                          12-JUN-98
Vellore

         1       2000 ana                            13-OCT-00
Pune

         2       3000 swara                          26-JUN-02
Pune


        ID     SALARY NAME                           DOB
---------- ---------- ------------------------------ ---------
ADDRESS
--------------------
         4       5000 rajni                          03-AUG-99
Chennai

         5       7000 rani                           23-DEC-00
Kolkata


SQL> select id from emp;

        ID
----------
         3
         1
         2
         4
         5

SQL> rename emp to emp1
  2  ;

Table renamed.

SQL> select emp from emp;
select emp from emp
                *
ERROR at line 1:
ORA-00942: table or view does not exist


SQL> select * from emp1;

        ID     SALARY NAME                           DOB
---------- ---------- ------------------------------ ---------
ADDRESS
--------------------
         3       6000 shiva                          12-JUN-98
Vellore

         1       2000 ana                            13-OCT-00
Pune

         2       3000 swara                          26-JUN-02
Pune


        ID     SALARY NAME                           DOB
---------- ---------- ------------------------------ ---------
ADDRESS
--------------------
         4       5000 rajni                          03-AUG-99
Chennai

         5       7000 rani                           23-DEC-00
Kolkata


SQL> rename emp1 to emp;

Table renamed.

SQL> alter table emp modify name varchar2(10);

Table altered.

SQL> select * from emp;

        ID     SALARY NAME       DOB       ADDRESS
---------- ---------- ---------- --------- --------------------
         3       6000 shiva      12-JUN-98 Vellore
         1       2000 ana        13-OCT-00 Pune
         2       3000 swara      26-JUN-02 Pune
         4       5000 rajni      03-AUG-99 Chennai
         5       7000 rani       23-DEC-00 Kolkata

SQL> alter table emp add status varchar2(10);

Table altered.

SQL> alter table employee modify id varchar2(3);
alter table employee modify id varchar2(3)
*
ERROR at line 1:
ORA-00942: table or view does not exist


SQL> alter table emp modify id varchar2(3);
alter table emp modify id varchar2(3)
                       *
ERROR at line 1:
ORA-01439: column to be modified must be empty to change datatype


SQL> alter table emp add age number(2);

Table altered.

SQL> alter table emp add age number(4);
alter table emp add age number(4)
                    *
ERROR at line 1:
ORA-01430: column being added already exists in table


SQL> alter table emp modify age number(4);

Table altered.

SQL> alter table emp drop column status;

Table altered.

SQL> alter table tablename rename column id to emp_no;
alter table tablename rename column id to emp_no
*
ERROR at line 1:
ORA-00942: table or view does not exist


SQL> alter table emp rename column id to emp_id;

Table altered.

SQL> rename emp to employee
  2  ;

Table renamed.

SQL> select * from employee;

    EMP_ID     SALARY NAME       DOB       ADDRESS                     AGE
---------- ---------- ---------- --------- -------------------- ----------
         3       6000 shiva      12-JUN-98 Vellore
         1       2000 ana        13-OCT-00 Pune
         2       3000 swara      26-JUN-02 Pune
         4       5000 rajni      03-AUG-99 Chennai
         5       7000 rani       23-DEC-00 Kolkata

SQL> insert into employee values(6,4500,'','14-jul-1995','Mumbai',25);

1 row created.

SQL> select * from employee;

    EMP_ID     SALARY NAME       DOB       ADDRESS                     AGE
---------- ---------- ---------- --------- -------------------- ----------
         3       6000 shiva      12-JUN-98 Vellore
         1       2000 ana        13-OCT-00 Pune
         2       3000 swara      26-JUN-02 Pune
         4       5000 rajni      03-AUG-99 Chennai
         5       7000 rani       23-DEC-00 Kolkata
         6       4500            14-JUL-95 Mumbai                       25

6 rows selected.

SQL> insert into employee(emp_id,salary,age) values(7,5600,16);

1 row created.

SQL> select * from employee;

    EMP_ID     SALARY NAME       DOB       ADDRESS                     AGE
---------- ---------- ---------- --------- -------------------- ----------
         3       6000 shiva      12-JUN-98 Vellore
         1       2000 ana        13-OCT-00 Pune
         2       3000 swara      26-JUN-02 Pune
         4       5000 rajni      03-AUG-99 Chennai
         5       7000 rani       23-DEC-00 Kolkata
         6       4500            14-JUL-95 Mumbai                       25
         7       5600                                                   16

7 rows selected.

SQL> select * from employee where emp_id = 6;

    EMP_ID     SALARY NAME       DOB       ADDRESS                     AGE
---------- ---------- ---------- --------- -------------------- ----------
         6       4500            14-JUL-95 Mumbai                       25

SQL> select * from employee where name = 'ana';

    EMP_ID     SALARY NAME       DOB       ADDRESS                     AGE
---------- ---------- ---------- --------- -------------------- ----------
         1       2000 ana        13-OCT-00 Pune

SQL> select * from employee where name = 'Ana';

no rows selected

SQL> select salary, address from employee where emp_id = 4;

    SALARY ADDRESS
---------- --------------------
      5000 Chennai

SQL> select * from employee where name is null;

    EMP_ID     SALARY NAME       DOB       ADDRESS                     AGE
---------- ---------- ---------- --------- -------------------- ----------
         6       4500            14-JUL-95 Mumbai                       25
         7       5600                                                   16

SQL> select * from employee where name is not null;

    EMP_ID     SALARY NAME       DOB       ADDRESS                     AGE
---------- ---------- ---------- --------- -------------------- ----------
         3       6000 shiva      12-JUN-98 Vellore
         1       2000 ana        13-OCT-00 Pune
         2       3000 swara      26-JUN-02 Pune
         4       5000 rajni      03-AUG-99 Chennai
         5       7000 rani       23-DEC-00 Kolkata

SQL> select emp_id empno, address city from employee;

     EMPNO CITY
---------- --------------------
         3 Vellore
         1 Pune
         2 Pune
         4 Chennai
         5 Kolkata
         6 Mumbai
         7

7 rows selected.

SQL> select distinct age from employee;

       AGE
----------

        25
        16

SQL> alter employee add status varchar2(10;
alter employee add status varchar2(10
      *
ERROR at line 1:
ORA-00940: invalid ALTER command


SQL> alter employee add status varchar2(10);
alter employee add status varchar2(10)
      *
ERROR at line 1:
ORA-00940: invalid ALTER command


SQL> alter table employee add status varchar2(10);

Table altered.

SQL> update employee set status = 'Intern';

7 rows updated.

SQL> select * from employee;

    EMP_ID     SALARY NAME       DOB       ADDRESS                     AGE
---------- ---------- ---------- --------- -------------------- ----------
STATUS
----------
         3       6000 shiva      12-JUN-98 Vellore
Intern

         1       2000 ana        13-OCT-00 Pune
Intern

         2       3000 swara      26-JUN-02 Pune
Intern


    EMP_ID     SALARY NAME       DOB       ADDRESS                     AGE
---------- ---------- ---------- --------- -------------------- ----------
STATUS
----------
         4       5000 rajni      03-AUG-99 Chennai
Intern

         5       7000 rani       23-DEC-00 Kolkata
Intern

         6       4500            14-JUL-95 Mumbai                       25
Intern


    EMP_ID     SALARY NAME       DOB       ADDRESS                     AGE
---------- ---------- ---------- --------- -------------------- ----------
STATUS
----------
         7       5600                                                   16
Intern


7 rows selected.

SQL> alter table employee modify salary number(6);
alter table employee modify salary number(6)
                            *
ERROR at line 1:
ORA-01440: column to be modified must be empty to decrease precision or scale


SQL> alter table employee modify address varchar2(10);

Table altered.

SQL> select * from employee;

    EMP_ID     SALARY NAME       DOB       ADDRESS           AGE STATUS
---------- ---------- ---------- --------- ---------- ---------- ----------
         3       6000 shiva      12-JUN-98 Vellore               Intern
         1       2000 ana        13-OCT-00 Pune                  Intern
         2       3000 swara      26-JUN-02 Pune                  Intern
         4       5000 rajni      03-AUG-99 Chennai               Intern
         5       7000 rani       23-DEC-00 Kolkata               Intern
         6       4500            14-JUL-95 Mumbai             25 Intern
         7       5600                                         16 Intern

7 rows selected.

SQL> update employee set age = 20 where emp_id = 5;

1 row updated.

SQL> update employee set age = &age where empid = &emp_id;
Enter value for age: 22
Enter value for emp_id: 3
old   1: update employee set age = &age where empid = &emp_id
new   1: update employee set age = 22 where empid = 3
update employee set age = 22 where empid = 3
                                   *
ERROR at line 1:
ORA-00904: "EMPID": invalid identifier


SQL> update employee set age = &age where emp_id = &emp_id;
Enter value for age: 22
Enter value for emp_id: 3
old   1: update employee set age = &age where emp_id = &emp_id
new   1: update employee set age = 22 where emp_id = 3

1 row updated.

SQL> /
Enter value for age: 20
Enter value for emp_id: 1
old   1: update employee set age = &age where emp_id = &emp_id
new   1: update employee set age = 20 where emp_id = 1

1 row updated.

SQL> /
Enter value for age: 18
Enter value for emp_id: 2
old   1: update employee set age = &age where emp_id = &emp_id
new   1: update employee set age = 18 where emp_id = 2

1 row updated.

SQL> /
Enter value for age: 21
Enter value for emp_id: 4
old   1: update employee set age = &age where emp_id = &emp_id
new   1: update employee set age = 21 where emp_id = 4

1 row updated.

SQL> select * from employee;

    EMP_ID     SALARY NAME       DOB       ADDRESS           AGE STATUS
---------- ---------- ---------- --------- ---------- ---------- ----------
         3       6000 shiva      12-JUN-98 Vellore            22 Intern
         1       2000 ana        13-OCT-00 Pune               20 Intern
         2       3000 swara      26-JUN-02 Pune               18 Intern
         4       5000 rajni      03-AUG-99 Chennai            21 Intern
         5       7000 rani       23-DEC-00 Kolkata            20 Intern
         6       4500            14-JUL-95 Mumbai             25 Intern
         7       5600                                         16 Intern

7 rows selected.

SQL> update employee set address = 'Delhi' where address is null;

1 row updated.

SQL> select * from employee;

    EMP_ID     SALARY NAME       DOB       ADDRESS           AGE STATUS
---------- ---------- ---------- --------- ---------- ---------- ----------
         3       6000 shiva      12-JUN-98 Vellore            22 Intern
         1       2000 ana        13-OCT-00 Pune               20 Intern
         2       3000 swara      26-JUN-02 Pune               18 Intern
         4       5000 rajni      03-AUG-99 Chennai            21 Intern
         5       7000 rani       23-DEC-00 Kolkata            20 Intern
         6       4500            14-JUL-95 Mumbai             25 Intern
         7       5600                      Delhi              16 Intern

7 rows selected.

SQL> update employee set salary = '', status = '' where emp_id = 5;

1 row updated.

SQL> select * from employee;

    EMP_ID     SALARY NAME       DOB       ADDRESS           AGE STATUS
---------- ---------- ---------- --------- ---------- ---------- ----------
         3       6000 shiva      12-JUN-98 Vellore            22 Intern
         1       2000 ana        13-OCT-00 Pune               20 Intern
         2       3000 swara      26-JUN-02 Pune               18 Intern
         4       5000 rajni      03-AUG-99 Chennai            21 Intern
         5            rani       23-DEC-00 Kolkata            20
         6       4500            14-JUL-95 Mumbai             25 Intern
         7       5600                      Delhi              16 Intern

7 rows selected.

SQL> update employee set name = '' where emp_id = 4;

1 row updated.

SQL> alter table employee add bruh varchar2(4);

Table altered.

SQL> update employee set bruh = 'BRUH' where name is null;

3 rows updated.

SQL> select * from employee
  2  ;

    EMP_ID     SALARY NAME       DOB       ADDRESS           AGE STATUS     BRUH
---------- ---------- ---------- --------- ---------- ---------- ---------- ----
         3       6000 shiva      12-JUN-98 Vellore            22 Intern
         1       2000 ana        13-OCT-00 Pune               20 Intern
         2       3000 swara      26-JUN-02 Pune               18 Intern
         4       5000            03-AUG-99 Chennai            21 Intern     BRUH
         5            rani       23-DEC-00 Kolkata            20
         6       4500            14-JUL-95 Mumbai             25 Intern     BRUH
         7       5600                      Delhi              16 Intern     BRUH

7 rows selected.

SQL> insert into employee(name,address,age,bruh) values('hola','uranus',99,'bro?');

1 row created.

SQL> select * from employee;

    EMP_ID     SALARY NAME       DOB       ADDRESS           AGE STATUS     BRUH
---------- ---------- ---------- --------- ---------- ---------- ---------- ----
         3       6000 shiva      12-JUN-98 Vellore            22 Intern
         1       2000 ana        13-OCT-00 Pune               20 Intern
         2       3000 swara      26-JUN-02 Pune               18 Intern
         4       5000            03-AUG-99 Chennai            21 Intern     BRUH
         5            rani       23-DEC-00 Kolkata            20
         6       4500            14-JUL-95 Mumbai             25 Intern     BRUH
         7       5600                      Delhi              16 Intern     BRUH
                      hola                 uranus             99            bro?

8 rows selected.

SQL> delete from employee where emp_id is null;

1 row deleted.

SQL> select * from employee;

    EMP_ID     SALARY NAME       DOB       ADDRESS           AGE STATUS     BRUH
---------- ---------- ---------- --------- ---------- ---------- ---------- ----
         3       6000 shiva      12-JUN-98 Vellore            22 Intern
         1       2000 ana        13-OCT-00 Pune               20 Intern
         2       3000 swara      26-JUN-02 Pune               18 Intern
         4       5000            03-AUG-99 Chennai            21 Intern     BRUH
         5            rani       23-DEC-00 Kolkata            20
         6       4500            14-JUL-95 Mumbai             25 Intern     BRUH
         7       5600                      Delhi              16 Intern     BRUH

7 rows selected.

SQL> delete from employee where bruh is not null;

3 rows deleted.

SQL> desc;
Usage: DESCRIBE [schema.]object[@db_link]
SQL> desc employee;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 EMP_ID                                             NUMBER(3)
 SALARY                                             NUMBER(10)
 NAME                                               VARCHAR2(10)
 DOB                                                DATE
 ADDRESS                                            VARCHAR2(10)
 AGE                                                NUMBER(4)
 STATUS                                             VARCHAR2(10)
 BRUH                                               VARCHAR2(4)

SQL> delete from employee;

4 rows deleted.

SQL> select * from employee;

no rows selected

SQL> truncate table employee;

Table truncated.

SQL> drop table employee;

Table dropped.

SQL> select * from employee;
select * from employee
              *
ERROR at line 1:
ORA-00942: table or view does not exist


SQL>