CREATE DATABASE HR;
USE HR;
CREATE TABLE employees (

	employee_id INT NOT NULL PRIMARY KEY UNIQUE,
    first_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30) NOT NULL,
    email VARCHAR(40) NOT NULL,
    phone_number CHAR(11) NOT NULL,
    hire_date DATE NOT NULL,
    job_id VARCHAR(30) NOT NULL,
    salary INT NOT NULL
    
);

ALTER TABLE employees
MODIFY COLUMN job_id VARCHAR(30);


INSERT INTO employees
VALUES (
	100,
	'Steven',
	'King',
	'SKING',
	'01756582588',
	STR_TO_DATE('17-JUN-1987', '%d-%M-%Y'),
	'AD_PRES',
	24000

	);

INSERT INTO employees
VALUES (
	101,
	'Neena',
	'Kochhar',
	'NKOCHHAR',
	'01756582554',
	STR_TO_DATE('21-SEP-1989', '%d-%M-%Y'),
	'AD_VP',
	17000

	);

INSERT INTO employees
VALUES (
	102,
	'Lex',
	'De Haan',
	'LDEHAAN',
	'01756582000',
	STR_TO_DATE('13-JAN-1993', '%d-%M-%Y'),
	'AD_VP',
	17000
	);

INSERT INTO employees
VALUES (
	103,
	'Alexander',
	'Hunold',
	'AHUNOLD',
	'01756582587',
	STR_TO_DATE('03-JAN-1990', '%d-%M-%Y'),
	'IT_PROG',
	9000

	);

INSERT INTO employees
VALUES (
	104,
	'Bruce',
	'Ernst',
	'BERNST',
	'01756582588',
	STR_TO_DATE('21-MAY-1991', '%d-%M-%Y'),
	'IT_PROG',
	6000

	);

INSERT INTO employees
VALUES (
	105,
	'David',
	'Austin',
	'DAUSTIN',
	'01756582577',
	STR_TO_DATE('25-JUN-1997', '%d-%M-%Y'),
	'IT_PROG',
	4800

	);

INSERT INTO employees
VALUES (
	106,
	'Valli',
	'Pataballa',
	'VPATABAL',
	'01756582579',
	STR_TO_DATE('05-FEB-1998', '%d-%M-%Y'),
	'IT_PROG',
	4800
	);

INSERT INTO employees
VALUES (
	107,
	'Diana',
	'Lorentz',
	'DLORENTZ',
	'01756582565',
	STR_TO_DATE('07-FEB-1999', '%d-%M-%Y'),
	'IT_PROG',
	4200
	);

INSERT INTO employees
VALUES (
	108,
	'Nancy',
	'Greenberg',
	'NGREENBE',
	'01756582580',
	STR_TO_DATE('17-AUG-1994', '%d-%M-%Y'),
	'FI_MGR',
	12000
	);

INSERT INTO employees
VALUES (
	109,
	'Daniel',
	'Faviet',
	'DFAVIET',
	'01756582599',
	STR_TO_DATE('16-AUG-1994', '%d-%M-%Y'),
	'FI_ACCOUNT',
	9000
	);

INSERT INTO employees
VALUES (
	110,
	'John',
	'Chen',
	'JCHEN',
	'01756582523',
	STR_TO_DATE('28-SEP-1997', '%d-%M-%Y'),
	'FI_ACCOUNT',
	8200
	);

INSERT INTO employees
VALUES (
	111,
	'Ismael',
	'Sciarra',
	'ISCIARRA',
	'01756582522',
	STR_TO_DATE('30-SEP-1997', '%d-%M-%Y'),
	'FI_ACCOUNT',
	7700
	);

INSERT INTO employees
VALUES (
	112,
	'Jose Manuel',
	'Urman',
	'JMURMAN',
	'01756582586',
	STR_TO_DATE('07-MAR-1998', '%d-%M-%Y'),
	'FI_ACCOUNT',
	7800
	);

INSERT INTO employees
VALUES (
	113,
	'Luis',
	'Popp',
	'LPOPP',
	'01756582583',
	STR_TO_DATE('07-DEC-1999', '%d-%M-%Y'),
	'FI_ACCOUNT',
	6900
	);

INSERT INTO employees
VALUES (
	114,
	'Den',
	'Raphaely',
	'DRAPHEAL',
	'01756582555',
	STR_TO_DATE('07-DEC-1994', '%d-%M-%Y'),
	'PU_MAN',
	11000
	);

INSERT INTO employees
VALUES (
	115,
	'Alexander',
	'Khoo',
	'AKHOO',
	'01756582570',
	STR_TO_DATE('18-MAY-1995', '%d-%M-%Y'),
	'PU_CLERK',
	3100
	);

INSERT INTO employees
VALUES (
	116,
	'Shelli',
	'Baida',
	'SBAIDA',
	'01756582565',
	STR_TO_DATE('24-DEC-1997', '%d-%M-%Y'),
	'PU_CLERK',
	2900
	);

INSERT INTO employees
VALUES (
	117,
	'Sigal',
	'Tobias',
	'STOBIAS',
	'01756582458',
	STR_TO_DATE('24-JUL-1997', '%d-%M-%Y'),
	'PU_CLERK',
	2800
	);

INSERT INTO employees
VALUES (
	118,
	'Guy',
	'Himuro',
	'GHIMURO',
	'01756582596',
	STR_TO_DATE('15-NOV-1998', '%d-%M-%Y'),
	'PU_CLERK',
	2600
	);

INSERT INTO employees
VALUES (
	119,
	'Karen',
	'Colmenares',
	'KCOLMENA',
	'01756582567',
	STR_TO_DATE('10-AUG-1999', '%d-%M-%Y'),
	'PU_CLERK',
	2500
	);

INSERT INTO employees
VALUES (
	 120,
	'Matthew',
	'Weiss',
	'MWEISS',
	'01756582356',
	STR_TO_DATE('18-JUL-1996', '%d-%M-%Y'),
	'ST_MAN',
	8000
	);
    
    SELECT * FROM employees;
    
    SELECT first_name, salary FROM employees
    WHERE last_name = "king";
    
    SELECT first_name, last_name FROM employees
    WHERE salary > 2000;
    
SELECT first_name, last_name, salary
FROM employees
WHERE salary > (SELECT AVG(salary) FROM employees);

SELECT job_id ,AVG(salary) AS Average , MAX(salary) AS Max_salary,
COUNT(*) AS Count_job_id
FROM employees
GROUP BY job_id;

SELECT * 
FROM employees
ORDER BY salary ASC
LIMIT 5,6;

SELECT COUNT(employee_id) AS total_employee, SUM(salary) AS total_salary
FROM employees;




    