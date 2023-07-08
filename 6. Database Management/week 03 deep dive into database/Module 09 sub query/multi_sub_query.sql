/* show the name and job id who is in same job and salary
 is greter the other job sector */
SELECT job_id, first_name
FROM employees
WHERE job_id = (SELECT job_id FROM employees WHERE employee_id = 103)
AND (SELECT salary FROM employees WHERE employee_id = 117);