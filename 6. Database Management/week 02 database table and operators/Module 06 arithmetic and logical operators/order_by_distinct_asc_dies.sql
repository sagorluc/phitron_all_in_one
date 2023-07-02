SELECT DISTINCT * FROM employees;

/*SORTED ACCENDING ORDER BY department_name column*/
SELECT  * 
FROM departments
ORDER BY department_name ASC;

/*SORTED BY DESCENDING ORDER BY department_name column*/
SELECT  * 
FROM departments
ORDER BY department_name DESC;

/* will take the data start from 5 to 7 (3 row will take)*/
SELECT  * 
FROM employees
LIMIT 3 OFFSET 5