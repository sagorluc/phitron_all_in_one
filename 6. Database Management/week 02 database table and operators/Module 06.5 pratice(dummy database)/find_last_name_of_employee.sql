/* rename the column and will show last_name and firs_name */
SELECT last_name AS LT_NAME, first_name AS FT_NAME FROM employees;

/* who has the salary above of ten thousend */
SELECT first_name, last_name, salary 
FROM employees
WHERE salary >= 10000

/* the name who has the middle char k */
SELECT first_name, last_name, salary 
FROM employees
WHERE first_name LIKE  "%k%"