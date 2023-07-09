/* with join statment and this is efficient way */
SELECT e.employee_id , e.first_name, d.department_name
FROM employees e JOIN departments d USING (department_id);


/* with join statment and this is efficient way */
SELECT e.employee_id , e.first_name, d.department_name
FROM employees e JOIN departments d ON e.department_id = d.department_id;