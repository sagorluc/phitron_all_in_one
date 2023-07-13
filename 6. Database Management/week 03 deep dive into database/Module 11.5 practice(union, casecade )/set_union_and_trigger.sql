
/* text convert into uppercase by triggering */
CREATE TRIGGER uppercase_trigger BEFORE INSERT ON student 
FOR EACH ROW SET NEW.s_name = UPPER(NEW.s_name);


/* SET UNION */
SELECT s_roll , s_name
FROM student
UNION
SELECT s_id , i_name
FROM student_info;

/* SET UNION ALL*/
SELECT s_roll , s_name
FROM student
UNION ALL
SELECT s_id , i_name
FROM student_info;

/* MINUS */
SELECT s_roll , s_name
FROM student
WHERE (s_roll, s_name) NOT IN 
(SELECT s_id , i_name
FROM student_info);

SELECT * FROM student_info;