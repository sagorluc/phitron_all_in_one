SELECT  *
FROM employees
WHERE salary > 2000 AND last_name = "King"

SELECT  *
FROM employees
WHERE salary > 2000 OR last_name = "King"

SELECT  *
FROM employees
WHERE salary > 20000 OR employee_id LIMIT 3,5