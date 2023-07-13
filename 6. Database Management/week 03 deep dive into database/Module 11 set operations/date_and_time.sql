SELECT DAYOFMONTH('2001-10-01');
SELECT MONTH('2001-10-01');
SELECT ADDDATE('2001-10-01', 31);
SELECT ADDTIME('2001-10-01 23:59:59.9999999','1:1:1.000002') AS add_time;
SELECT CONVERT_TZ('2002-10-01 12:00:00','GMT','MET');
SELECT CONVERT_TZ('2001-10-01 12:00:00','+00:00','+10:00');
SELECT CURDATE();
SELECT CURTIME();
SELECT DATE('2001-10-01 12:00:00');
SELECT DATEDIFF('2001-10-01 12:59:59','2001-09-30');
SELECT DATE_ADD('2001-10-01', INTERVAL 1 DAY);
SELECT DATE_SUB('2001-10-01 ', INTERVAL 1 YEAR);
SELECT DATE_FORMAT('2099-12-31','%W %M %Y');
SELECT DATE_FORMAT('2023-07-13','%H %I %S');
SELECT DATE_FORMAT('2099-12-31','%D %Y %A %D %M %B %J');
SELECT DAYOFMONTH('2023-07-13 12:00:00');
SELECT DAYOFWEEK('2023-07-13 12:00:00');
SELECT DAYOFYEAR('2023-07-18 12:00:00');
SELECT DATE_FORMAT('2023-07-18 12:00:00', GET_FORMAT(DATE, 'EUR'));