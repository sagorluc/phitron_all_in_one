CREATE DATABASE phitron;
USE phitron;

CREATE TABLE student(

	s_roll INT NOT NULL PRIMARY KEY,
    s_name VARCHAR(30) NOT NULL,
    age INT NOT NULL

);

CREATE TABLE course(

	c_id INT NOT NULL PRIMARY KEY,
    c_name VARCHAR(30) NOT NULL
);

CREATE TABLE enroll(
	s_roll INT NOT NULL ,
    c_id INT NOT NULL ,
    j_date DATE NOT NULL,
    
    PRIMARY KEY (s_roll, c_id),
    
    FOREIGN KEY (s_roll) REFERENCES student(s_roll)
    ON DELETE CASCADE,
    
    FOREIGN KEY (c_id) REFERENCES course(c_id)
    ON DELETE CASCADE
    
);

DROP TABLE enroll;

INSERT INTO student VALUES
(1, 'sagor ahmed', 25),
(2, 'jakir uzzaman', 26),
(3, 'saiful islam', 29),
(4, 'ismail hossen', 35),
(5, 'shimul', 49);

SELECT * FROM student;

INSERT INTO course VALUES
(101, 'C programing'),
(102, 'C++ programing'),
(103, 'python programing'),
(104, 'database');

SELECT * FROM course;

INSERT INTO enroll VALUES
(1, 101, '2023-05-06'),
(1, 102, '2023-01-10'),
(3, 104, '2022-07-15'),
(2, 103, '2021-03-27');

SELECT * FROM enroll;

DELETE FROM student
WHERE s_roll = 3;








