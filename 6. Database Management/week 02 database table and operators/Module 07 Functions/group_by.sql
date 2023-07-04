SELECT * FROM employees;

SELECT job_id,COUNT(*) AS total_employee
FROM employees
GROUP BY job_id;

SELECT job_id, MAX(salary), COUNT(*)
FROM employees
GROUP BY job_id;

SELECT job_id, MIN(salary), COUNT(*)
FROM employees
GROUP BY job_id;

SELECT job_id, SUM(salary), COUNT(*)
FROM employees
GROUP BY job_id;

SELECT job_id, AVG(salary), COUNT(*)
FROM employees
GROUP BY job_id;

SELECT last_name
FROM employees
GROUP BY last_name;

SELECT first_name, COUNT(*), MAX(first_name)
FROM employees
GROUP BY first_name;