/* if my salary is greter then PU_CLERK then will show */
SELECT first_name, salary, job_id
FROM employees
WHERE job_id != "PU_CLERK" AND 
salary > ANY (SELECT salary FROM employees WHERE job_id = "PU_CLERK" );

/* show my salary is greter then 3 person */
SELECT *  /* main query */
FROM employees  E1
WHERE 3 <= 
(SELECT COUNT(*) /* sub query */
FROM employees  E2
WHERE E1.salary < E2.salary);

SELECT last_name , salary , job_id
FROM employees E1
WHERE NOT EXISTS 
(SELECT * 
FROM employees E2
WHERE E1.salary < E2.salary);
