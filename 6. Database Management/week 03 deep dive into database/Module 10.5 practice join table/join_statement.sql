SELECT e.first_name , e.last_name, d.department_name
FROM employees e JOIN departments d 
ON e.department_id = d.department_id
WHERE e.last_name = "king";


SELECT e.first_name , e.last_name, d.department_name
FROM employees e , departments d 
WHERE e.last_name = "king";
