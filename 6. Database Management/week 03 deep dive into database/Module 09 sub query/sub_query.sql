USE hr;
SELECT * FROM employees;

/* use sub query to show the less or equal salary of spacific person */
SELECT first_name , salary
FROM employees							/* sub query */
WHERE employee_id != 103 AND salary <= (SELECT salary FROM employees WHERE employee_id = 103); 

SELECT job_id, first_name, salary
FROM employees
WHERE salary = (SELECT salary FROM employees WHERE employee_id = 103 );