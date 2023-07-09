/* self join statment */
SELECT e.first_name AS employee_name, m.first_name AS manager_name
FROM employees e JOIN employees m
ON e.manager_id = m.employee_id;
