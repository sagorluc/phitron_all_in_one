/* showing all the tables in database */
USE hr;
SHOW TABLES;

/* showing total number of tables in database */
SELECT COUNT(*) AS total_table
FROM information_schema.tables WHERE table_schema = "hr"