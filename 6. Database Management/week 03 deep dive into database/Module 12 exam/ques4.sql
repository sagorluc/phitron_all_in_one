/* From the HR Database, determine the second highest
   salary of an employee. */

SELECT MAX(salary) AS second_maximum_salary
FROM employees
WHERE salary < (SELECT MAX(salary) FROM employees);
