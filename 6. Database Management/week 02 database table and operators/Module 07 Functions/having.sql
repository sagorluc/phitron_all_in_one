SELECT * FROM employees;

SELECT job_id,COUNT(*) AS total_employee
FROM employees
GROUP BY job_id
HAVING COUNT(*) > 1;

SELECT job_id, MAX(salary), COUNT(*)
FROM employees
GROUP BY job_id
HAVING MAX(salary) > 15000;

SELECT job_id, MIN(salary), COUNT(*)
FROM employees
GROUP BY job_id
HAVING MIN(salary) < 15000;

SELECT job_id, SUM(salary), COUNT(*)
FROM employees
GROUP BY job_id
HAVING SUM(salary) > 8000;

SELECT job_id, AVG(salary), COUNT(*)
FROM employees
GROUP BY job_id
HAVING AVG(salary) > 10000;