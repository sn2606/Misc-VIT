alter table hospital_bill add consulting_physician varchar2(6);

Table altered.

SQL> select * from hospital_bill;

    INV_NO INV_DATE  PAT_ID    BILL_AMOUNT PAYMENT_TY   DISCOUNT CONSUL
---------- --------- --------- ----------- ---------- ---------- ------
1001000101 14-JUL-20 P-01-001       100500 Cheque             15
1001000201 13-MAY-20 P-01-002       101546 Transfer           25
1001000301 15-JUL-20 P-01-003        13450 Card               15

SQL> update hospital_bill set consulting_physician = 'D0001' where pat_id = 'P-01-001';

1 row updated.

SQL> update hospital_bill set consulting_physician = 'D0001' where pat_id = 'P-01-002';

1 row updated.

SQL> update hospital_bill set consulting_physician = 'D0004' where pat_id = 'P-01-003';

1 row updated.

SQL> alter table hospital_bill add constraint con_phys_fk foreign key(consulting_physician) references Doctor(doc_id);

Table altered.

SQL> select * from hospital_bill;

    INV_NO INV_DATE  PAT_ID    BILL_AMOUNT PAYMENT_TY   DISCOUNT CONSUL
---------- --------- --------- ----------- ---------- ---------- ------
1001000101 14-JUL-20 P-01-001       100500 Cheque             15 D0001
1001000201 13-MAY-20 P-01-002       101546 Transfer           25 D0001
1001000301 15-JUL-20 P-01-003        13450 Card               15 D0004

SQL> alter table patient drop column address;
Table altered.

SQL> alter table Patient add street varchar2(15);
Table altered.

SQL> alter table Patient add city varchar2(10);
Table altered.

SQL> alter table Patient add pincode number(10);
Table altered.

SQL> update patient set street = 'Tilak Rd.', city = 'Pune', pincode = 411030 where pat_id = 'P-01-001';
1 row updated.

SQL> update patient set street = 'MG Rd.', city = 'Pune', pincode = 411001 where pat_id = 'P-01-002';
1 row updated.

SQL> update patient set street = 'Kalyaninagar', city = 'Pune', pincode = 411006 where pat_id = 'P-01-003';
1 row updated.

SQL> select * from Patient;

PAT_ID    PAT_NAME             DOB       GE    CONTACT SYMPTOMS             STREET          CITY          PINCODE
--------- -------------------- --------- -- ---------- -------------------- --------------- ---------- ----------
P-01-001  Nina Torev           12-JUN-10 F  8897889709 Chest congestion     Tilak Rd.       Pune           411030
P-01-002  Kalyani Shah         14-JUL-01 F  9878987890 Loose motions        MG Rd.          Pune           411001
P-01-003  Ajit Adani           25-DEC-70 M  8976567890 Cold and weakness    Kalyaninagar    Pune           411006

SQL> alter table lab_tests add test_time1 varchar2(15) constraint test_time1_check check(test_time1 in ('Before Food', 'After Food'));
Table altered.

SQL> update lab_tests set test_time1 = 'Before Food' where pat_id = 'P-01-001';
1 row updated.

SQL> update lab_tests set test_time1 = 'Before Food' where pat_id = 'P-01-002';
1 row updated.

SQL> update lab_tests set test_time1 = 'After Food' where pat_id = 'P-01-002';
1 row updated.


SQL> update lab_tests set test_time1 = 'Before Food' where pat_id = 'P-01-003';
1 row updated.

SQL> select * from lab_tests;

TEST_ID    PAT_ID    TEST_DATE TEST_TIME                                                                   TEST_TIME1
---------- --------- --------- --------------------------------------------------------------------------- ---------------
TP-01-001  P-01-001  14-FEB-20 14-FEB-20 08.03.23.000000 AM                                                Before Food
TP-01-002  P-01-002  29-FEB-20 29-FEB-20 04.05.45.000000 PM                                                After Food
TP-01-003  P-01-003  01-JUL-20 01-JUL-20 09.00.00.000000 AM                                                Before Food

SQL> alter table lab_tests drop constraint test_time1_check;

Table altered.

SQL> alter table staff drop column address;

Table altered.

SQL> alter table staff add door_no number(3);

Table altered.

SQL> alter table staff add street varchar2(15);

Table altered.

SQL> alter table staff add city varchar2(10);

Table altered.

SQL> alter table staff add pincode number(10);

Table altered.

SQL> update staff set door_no = 1, street = 'Tilak Rd.', city = 'Pune', pincode = 411030 where staff_id = 'S0001';

1 row updated.

SQL> update staff set door_no = 2, street = 'Yerawada', city = 'Pune', pincode = 411006 where staff_id = 'S0003';

1 row updated.

SQL> update staff set door_no = 3, street = 'Prabhat Rd.', city = 'Pune', pincode = 411004 where staff_id = 'S0002';

1 row updated.

SQL> select * from Staff;

STAFF_ STAFF_NAME           CATEGORY             DESIGNATION          DOB          CONTACT    DEPT_NO    DOOR_NO STREET          CITY          PINCODE
------ -------------------- -------------------- -------------------- --------- ---------- ---------- ---------- --------------- ---------- ----------
S0001  Chaitanya Babu       Junior               Nurse                12-MAR-98 9999999999        102          1 Tilak Rd.       Pune           411030
S0003  Asmita Rao           Senior               Technician           13-OCT-90 8769054321        190          2 Yerawada        Pune           411006
S0002  Reyna Ramirez        Junior               Junior attender      26-JUN-95 7066227686        190          3 Prabhat Rd.     Pune           411004



SQL> create table Medicines(med_name varchar2(25), 
brand varchar2(20), 
manu_date date,
exp_date date,
constraint manu_exp_chk check(manu_date < exp_date));


SQL> alter table prescribed_medicines drop column dosage;
Table altered.

SQL> alter table prescribed_medicines drop column brand;
Table altered.

SQL> select * from prescribed_medicines;

PRES_ID   MEDICINE_NAME        DAYS_OF_DOSE
--------- -------------------- ------------
PR00028   Xofluza                         5

SQL> alter table medicines add constraint med_name_pk primary key(med_name);
Table altered.

SQL> alter table prescribed_medicines add constraint med_name_fk foreign key(medicine_name) references medicines(med_name);
Table altered.

SQL> select * from Doctor;

DOC_ID DOC_NAME             GE DOB       SPECIALIST           QUALIFICAT    CONTACT ADDRESS                 DEPT_NO
------ -------------------- -- --------- -------------------- ---------- ---------- -------------------- ----------
D0001  Rajeev Maseen        M  31-JUL-90 Cardiology           MBBS MDS   8986754309 Yerawada, Pune              102
D0002  Shahiza Ibrahim      F  30-JUN-89 Gynaecology          MDS        8690563412 Dhayari, Pune               118
D0003  Vishal Patrawalla    M  12-FEB-80 Cardiology           MDS        9768523410 Prabhat Rd., Pune           102
D0004  Avani Zanwar         F  24-OCT-91 Neurology            MBBS MDS   8696857435 Kalyaninagar, Pune          190

SQL> create view Doctor_Cardiology as select doc_id, doc_name, gender from Doctor where specialist = 'Cardiology';
View created.

SQL> select * from doctor_cardiology;

DOC_ID DOC_NAME             GE
------ -------------------- --
D0001  Rajeev Maseen        M
D0003  Vishal Patrawalla    M

SQL> select * from Department;

   DEPT_NO DEPT_NAME            ROOM_N   FLOOR_NO HOD    ESTD_DATE
---------- -------------------- ------ ---------- ------ ---------
       102 Cardiology           R-102           1 D0003  12-JAN-11
       118 Gynaecology          R-118           2 D0002  10-JAN-10
       190 Neurology            R-190           3 D0004  21-JUN-13

SQL> alter table department add no_of_staff number(6) constraint no_staff_chk check(no_of_staff > 0);
Table altered.

SQL> update department set no_of_staff = 50 where dept_no = 102;
1 row updated.

SQL> update department set no_of_staff = 55 where dept_no = 118;
1 row updated.

SQL> update department set no_of_staff = 30 where dept_no = 190;
1 row updated.

SQL> select * from Department;

   DEPT_NO DEPT_NAME            ROOM_N   FLOOR_NO HOD    ESTD_DATE NO_OF_STAFF
---------- -------------------- ------ ---------- ------ --------- -----------
       102 Cardiology           R-102           1 D0003  12-JAN-11          50
       118 Gynaecology          R-118           2 D0002  10-JAN-10          55
       190 Neurology            R-190           3 D0004  21-JUN-13          30
	   
SQL> insert into Doctor values('&Doc_ID', '&Doc_Name', '&Gender', '&dob', '&Specialist', '&qualification', &Contact, '&Address', &Dept_no);
Enter value for doc_id: D0005
Enter value for doc_name: Raghavan
Enter value for gender: M
Enter value for dob: 27-OCT-91
Enter value for specialist: Psychology
Enter value for qualification: MBBS MDS
Enter value for contact: 9807654655
Enter value for address: Shastri Rd., Pune
Enter value for dept_no: 101
old   1: insert into Doctor values('&Doc_ID', '&Doc_Name', '&Gender', '&dob', '&Specialist', '&qualification', &Contact, '&Address', &Dept_no)
new   1: insert into Doctor values('D0005', 'Raghavan', 'M', '27-OCT-91', 'Psychology', 'MBBS MDS', 9807654655, 'Shastri Rd., Pune', 101)

1 row created.

SQL> /
Enter value for doc_id: D0101
Enter value for doc_name: Meena Bose
Enter value for gender: F
Enter value for dob: 30-Jan-1999
Enter value for specialist: Psychology
Enter value for qualification: MBBS
Enter value for contact: 9888777789
Enter value for address: Lakshmi Rd., Pune
Enter value for dept_no: 101
old   1: insert into Doctor values('&Doc_ID', '&Doc_Name', '&Gender', '&dob', '&Specialist', '&qualification', &Contact, '&Address', &Dept_no)
new   1: insert into Doctor values('D0101', 'Meena Bose', 'F', '30-Jan-1999', 'Psychology', 'MBBS', 9888777789, 'Lakshmi Rd., Pune', 101)

1 row created.
	   
insert into Department values(101, 'Psychology', 'R-101', 4, 'D0005', '16-MAY-2018', 20);

SQL> insert into staff values('S0004', 'Alisha Mommen', 'Junior', 'Nurse', '28-MAR-99', 9000000000, 101, 4, 'Shastri Rd.', 'Pune', 411030);

1 row created.

SQL> insert into staff values('S0005', 'Alyssa Jain', 'Junior', 'Technician', '28-MAY-99', 9000990000, 102, 5, 'Shastri Rd.', 'Pune', 411030);

1 row created.

insert into test_types values('T-1111', 'Glucose Test', 20, 50, 'Test blood glucose', 'S0005');

SQL> insert into medicines values('Ranbaxy', 'XYZ', '13-SEP-2020', '18-SEP-2021');

SQL> insert into patient values('P-03-004', 'Gayle', '01-JAN-2001', 'M', 9990009990, 'Cold and weakness', 'Lakshmi Rd.', 'Pune', 411030);

1 row created.

SQL> insert into patient values('P-01-101', 'Mani', '01-JAN-2002', 'F', 9991009990, 'Cold and weakness', 'Lakshmi Rd.', 'Pune', 411030);

1 row created.

SQL> insert into patient values('P-01-220', 'Steve', '01-JAN-2003', 'M', 9991109990, 'Cold and weakness', 'Lakshmi Rd.', 'Pune', 411030);

1 row created.

SQL> insert into patient values('P-01-050', 'Karthik', '01-JAN-2004', 'M', 9991119990, 'Cold and weakness', 'Lakshmi Rd.', 'Pune', 411030);

1 row created.

SQL> insert into in_patient values('P-03-004', '15-MAR-2017', 101, '15-MAR-2017 09.00.00.00 AM', '25-MAR-2017 09.00.00.00 AM', 'Influenza');

1 row created.

SQL> insert into in_patient values('P-01-101', '18-AUG-2020', 101, '18-AUG-2020 09.00.00.00 AM', '28-AUG-2020 09.00.00.00 AM', 'Influenza');

1 row created.

SQL> insert into appointment values('PA-0000004', 'P-01-220', 'D0101', 'S0004', 'R-412', '16-JUL-2020', '16-JUN-2020 10.00.00.00 AM');

1 row created.

SQL> insert into appointment values('PA-0000005', 'P-03-004', 'D0101', 'S0004', 'R-412', '15-MAR-2017', '15-MAR-2017 10.00.00.00 AM');

1 row created.


SQL> insert into appointment values('PA-0000006', 'P-01-101', 'D0101', 'S0004', 'R-412', '18-AUG-2020', '18-AUG-2020 07.00.00.00 AM');

1 row created.

SQL> insert into prescription values('PR00022', 'PA-0000005', '15-MAR-2017', '15-MAR-2017 12.00.00.00 PM', 'Influenza');

1 row created.

SQL> insert into prescription values('PR00067', 'PA-0000006', '18-AUG-2020', '18-AUG-2020 12.00.00.00 PM', 'Influenza');

1 row created.

SQL> insert into prescribed_medicines values('PR00022', 'Ranbaxy', 7);

1 row created.

SQL> insert into prescribed_medicines values('PR00067', 'Ranbaxy', 7);

1 row created.

SQL> insert into in_patient_prescription values('P-03-004', 'PR00022', NULL, NULL);

1 row created.

SQL> insert into in_patient_prescription values('P-01-101', 'PR00067', NULL, NULL);

1 row created.

SQL> insert into hospital_bill values(1001000401, '18-NOV-2019', 'P-01-220', 100000, 'Cred Card', 0, 'D0002');

1 row created.

SQL> insert into hospital_bill values(1001000501, '20-AUG-2020', 'P-01-050', 100000, 'Deb Card', 0, 'D0002');

1 row created.

SQL> insert into lab_tests values('TP-01-101', 'P-01-101', '19-AUG-2020', '19-AUG-2020 03.00.00.00 PM', 'After Food');

1 row created.

SQL> insert into test_results values('TP-01-101', 'T-1111', 'Positive');

1 row created.

