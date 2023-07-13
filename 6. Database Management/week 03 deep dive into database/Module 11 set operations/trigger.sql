/* trigger got lot of functionality */
/* this trigger will work when the user will insert his/her name 
   into database the word will insert by uppercase */
CREATE TRIGGER uppercase_trigger BEFORE INSERT ON users
FOR EACH ROW
BEGIN
    SET NEW.name = UPPER(NEW.name);
END;


INSERT INTO users (id, name) VALUES (1, 'John');
