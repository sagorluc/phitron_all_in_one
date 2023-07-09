/* without join statment and this is not efficient */
SELECT employee_id , first_name , department_name
FROM employees e , departments d
WHERE e.department_id = d.department_id;