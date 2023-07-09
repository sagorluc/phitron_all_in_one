/* inner, left, right and full join */
SELECT col1, col2, col3
FROM table1 t1
INNER table2 t2  /* will show only common things form two tables */
ON t1.c_id = t2.c_id;

SELECT col1, col2, col3
FROM table1 t1
LEFT table2 t2  /* will show all things form left table and common things from right table */
ON t1.c_id = t2.c_id;

SELECT col1, col2, col3
FROM table1 t1
RIGHT table2 t2  /* will show all things form right table and common things from left table */
ON t1.c_id = t2.c_id;

SELECT col1, col2, col3
FROM table1 t1
FULL table2 t2  /* will show all things from two tables  */
ON t1.c_id = t2.c_id;
