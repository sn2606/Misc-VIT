create table Doctor(Doc_ID varchar2(6) not null, 
Doc_Name varchar2(20) not null, 
Gender varchar2(2) not null, 
dob date not null, 
Specialist varchar2(20) not null, 
qualification varchar2(10) not null, 
Contact number(10) not null, 
Address varchar2(20) not null, 
Dept_no number(3) not null, 
constraint doc_id_pk primary key(Doc_ID), 
constraint doc_id_format check(Doc_ID like ('D____')), 
constraint doc_gend_format check(Gender in ('M', 'F', 'T')), 
constraint doc_dob_cons check(dob between date '1965-01-01' and date '2000-12-08'), 
constraint doc_contact_format check(Contact like ('__________')));


create table department(Dept_no number(3) not null, 
dept_name varchar2(20) not null, 
room_no varchar2(6) not null, 
floor_no number(3) not null, hod varchar2(6) not null, 
estd_date date not null,
constraint dept_no_pk primary key(Dept_no), 
constraint dept_roomno_form check(room_no like ('R-___')), 
constraint dept_floor_cons check(floor_no between 0 and 10), 
constraint dept_hod_fk foreign key(hod) references Doctor(Doc_ID), 
constraint dept_estd_cons check(estd_date > date '2010-01-01'));

alter table Doctor add constraint doc_dept_fk foreign key(Dept_no) references department(Dept_no);
 
create table Staff(Staff_ID varchar2(6) not null, 
Staff_Name varchar2(20) not null,
Category varchar2(20) not null,
Designation varchar2(20) not null,
dob date not null, 
Contact number(10) not null, 
Address varchar2(20) not null, 
Dept_no number(3) not null, 
constraint staff_id_pk primary key(Staff_ID), 
constraint staff_id_format check(Staff_ID like ('S____')), 
constraint staff_dob_cons check(dob between date '1965-01-01' and date '2002-01-01'), 
constraint staff_contact_format check(Contact like ('__________')),
constraint staff_dept_fk foreign key(Dept_no) references department(Dept_no));

create table Patient(Pat_ID varchar2(9) not null, 
Pat_Name varchar2(20) not null, 
dob date not null, 
Gender varchar2(2) not null,
Contact number(10) not null, 
Address varchar2(20) not null,
constraint Pat_id_pk primary key(Pat_ID), 
constraint Pat_id_format check(Pat_ID like ('P-__-___')), 
constraint Pat_gend_format check(Gender in ('M', 'F', 'T')), 
constraint Pat_dob_cons check(dob > date '1910-01-01'), 
constraint Pat_contact_format check(Contact like ('__________')));

create table in_patient(Pat_ID varchar2(9) not null,
date_of_admission date not null,
bed_no varchar2(13) not null,
start_time timestamp(2) not null,
end_time timestamp(2),
constraint ip_id_pk primary key(Pat_ID),
constraint ip_id_fk foreign key(Pat_ID) references Patient(Pat_ID),
constraint ip_doa_cons check(date_of_admission > date '2010-01-01'),
constraint ip_bed_format check(bed_no like ('F__-R___-B__')),
constraint ip_start_cons check(start_time between timestamp date_of_admission and end_time));

create table in_patient_presciption(Pat_ID varchar2(9) not null, 
Pres_ID varchar2(9) not null,
constraint ipp_id_fk foreign key(Pat_ID) references Patient(Pat_ID));

create table appointment(App_ID varchar2(10) not null, 
Pat_ID varchar2(9) not null,
Doc_ID varchar2(6) not null,
Nurse_ID varchar2(6) not null,
consult_room_no varchar2(6) not null,
app_date date not null,
app_time timestamp not null,
constraint app_id_pk primary key(App_ID),
constraint app_id_format check(App_ID like ('PA-_______')),
constraint app_pat_fk foreign key(Pat_ID) references Patient(Pat_ID),
constraint app_doc_fk foreign key(Doc_ID) references Doctor(Doc_ID),
constraint app_nurse_fk foreign key(Nurse_ID) references Staff(Staff_ID),
constraint consult_room_no check(consult_room_no like ('R-___')));

alter table appointment add constraint app_date_cons check(app_date > date '2010-01-01');

create table Prescription(Pres_ID varchar2(9) not null,
App_ID varchar2(10) not null,
Pres_date date not null,
Pres_time timestamp not null,
Diagnosis_detail varchar2(30) not null,
constraint pres_id_pk primary key(Pres_ID),
constraint pres_app_fk foreign key(App_ID) references appointment(App_ID),
constraint pres_date_cons check(Pres_date > date '2010-01-01'));

alter table in_patient_presciption add constraint ip_pres_fk foreign key(Pres_ID) references Prescription(Pres_ID);


create table prescribed_medicines(Pres_ID varchar2(9) not null,
medicine_name varchar2(20) not null,
dosage varchar2(20) not null,
brand varchar2(20) not null,
constraint med_id_pk primary key(Pres_ID),
constraint med_pres_fk foreign key(Pres_ID) references Prescription(Pres_ID));


create table hospital_bill(inv_no number(10) not null,
inv_date date not null,
Pat_ID varchar2(9) not null,
bill_amount number(7) not null,
payment_type varchar2(10) not null,
discount varchar2(4),
constraint bill_invn_pk primary key(inv_no),
constraint bill_invn_cons check(inv_date > date '2010-01-01'),
constraint bill_pat_fk foreign key(Pat_ID) references Patient(Pat_ID),
constraint bill_amt_cons check(bill_amount between 0 and 5000000));

create table lab_tests(Test_ID varchar2(10) not null,
Pat_ID varchar2(9) not null,
test_date date not null,
test_time timestamp not null,
constraint lab_id_pk primary key(Test_ID),
constraint lab_id_format check(Test_ID like ('TP-______')),
constraint lab_pat_fk foreign key(Pat_ID) references Patient(Pat_ID),
constraint lab_date_cons check(test_date > date '2010-01-01'));


create table test_results(Test_ID varchar2(10) not null,
TT_ID varchar2(7)  not null,
test_res varchar2(20) not null,
constraint res_id_pk primary key(Test_ID),
constraint res_id_fk foreign key(Test_ID) references lab_tests(Test_ID));


create table test_types(TT_ID varchar2(7)  not null,
description varchar2(20) not null,
low_value varchar2(20) not null,
high_value varchar2(20) not null,
test_method varchar2(20) not null,
technician varchar2(6) not null,
constraint ttp_id_pk primary key(TT_ID),
constraint ttp_id_format check(TT_ID like ('T-____')),
constraint ttp_tech_fk foreign key(technician) references Staff(Staff_ID));

alter table test_results add constraint res_tt_fk foreign key(TT_ID) references test_types(TT_ID);

alter table department add constraint dept_no_format check(Dept_no like ('D-___'));
alter table in_patient drop constraint ip_bed_format;
alter table in_patient modify bed_no number(5);
alter table in_patient add constraint ip_bed_format check(bed_no between 1 and 40000);
alter table Prescription add constraint pres_id_format check(Pres_ID like ('PR_____'));
alter table test_types modify low_value number(4);
alter table test_types modify high_value number(4);
alter table hospital_bill modify discount number(3);

insert into Doctor values('&Doc_ID', '&Doc_Name', '&Gender', '&dob', '&Specialist', '&qualification', &Contact, '&Address', &Dept_no);
insert into department values(&Dept_no, '&dept_name', '&room_no', &floor, '&hod', '&estd_date');
insert into Staff values('&Staff_ID', '&Staff_Name', '&Category', '&Designation', '&dob', &Contact, '&Address', &Dept_no);
insert into Patient values('&Pat_ID', '&Pat_Name', '&dob', '&Gender', &Contact);
insert into in_patient values('&Pat_ID', '&date_of_admission', &bed_no, '&start_time', '&end_time');
insert into appointment values('&App_ID', '&Pat_ID', '&Doc_ID', '&Nurse_ID', '&consult_room_no', '&app_date', '&app_time');
insert into Prescription values('&Pres_ID', '&App_ID', '&Pres_date', '&Pres_time', '&Diagnosis_detail');
insert into in_patient_presciption values('&Pat_ID', '&Pres_ID'); 
insert into prescribed_medicines values('&Pres_ID', '&medicine_name', '&dosage', '&brand');
insert into hospital_bill values(&inv_no, '&inv_date', '&Pat_ID', &bill_amount, '&payment_type', &discount); 
insert into lab_tests values('&Test_ID', '&Pat_ID', '&test_date', '&test_time');
insert into test_types values('&TT_ID', '&description', &low_value, &high_value, '&test_method', '&technician');
insert into test_results values('&Test_ID', '&TT_ID', '&test_res');


SQL> alter table in_patient add diagnosis varchar2(20);
Table altered.

SQL> update in_patient set diagnosis = 'Pneumonia' where Pat_ID = 'P-01-001';
1 row updated.

SQL> update in_patient set diagnosis = 'Stomach infection' where Pat_ID = 'P-01-002';
1 row updated.

SQL> update in_patient set diagnosis = 'Influenza' where Pat_ID = 'P-01-003';
1 row updated.

SQL> select * from in_patient;

SQL> alter table Patient add symptoms varchar2(20);

Table altered.

SQL> update Patient set symptoms = 'Chest congestion' where Pat_ID = 'P-01-001';

1 row updated.

SQL> update Patient set symptoms = 'Loose motions' where Pat_ID = 'P-01-002';

1 row updated.

SQL> update Patient set symptoms = 'Cold and weakness' where Pat_ID = 'P-01-003';

1 row updated.

SQL> select * from Patient;

SQL> alter table in_patient_prescription add Test_ID varchar2(10);

Table altered.

SQL> update in_patient_prescription set Test_ID = 'TP-01-001' where Pat_ID = 'P-01-001';

1 row updated.

SQL> update in_patient_prescription set Test_ID = 'TP-01-002' where Pat_ID = 'P-01-002';

1 row updated.

SQL> update in_patient_prescription set Test_ID = 'TP-01-003' where Pat_ID = 'P-01-003';

1 row updated.

SQL> select * from in_patient_prescription;

SQL> alter table prescribed_medicines add days_of_dose number(3);

Table altered.

SQL> update prescribed_medicines set days_of_dose = 10 where Pres_ID = 'PR00012';

1 row updated.

SQL> update prescribed_medicines set days_of_dose = 7 where Pres_ID = 'PR00045';

1 row updated.

SQL> update prescribed_medicines set days_of_dose = 5 where Pres_ID = 'PR00028';

1 row updated.
