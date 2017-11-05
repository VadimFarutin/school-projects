<!DOCTYPE HTML>
<html>
<head>
	<title>Add</title>
	<meta charset='utf-8'>
	<link rel='shortcut icon' href='/icon.png' type='image/gif' />
</head>
<body>
<?php
	function add()
	{
		$link = mysqli_connect('localhost', 'root', '', 'cl11125');
		if (!$link || !mysqli_set_charset($link, 'utf8')) {
			$err_no = mysqli_connect_errno($link);
			$err = mysqli_connect_error($link);
			die("Connection error ($err_no) $err\n");
		}
		mysqli_query($link, "INSERT INTO students(Name, Surname, Birthday, Form, FormIndex) VALUES
							 (\"" . $_POST['name'] . "\", \"" . 
								  $_POST['surname'] . "\", '" . 
								  $_POST['birthday'] . "', " . 
								  $_POST['form'] . ", " . 
								  $_POST['formIndex'] . ")"); 
		mysqli_close($link);
	}
	if (array_key_exists('name', $_POST))
		add();
?>
	<form action='' method='post' type='submit'>
		<input type='text' name='name' value='name'>
		<br><input type='text' name='surname' value='surname'>
		<br><input type='text' name='birthday' value='YYYY-MM-DD'>
		<br><input type='text' name='form' value='form'>
		<br><input type='text' name='formIndex' value='formIndex'>
		<br><input type='submit' name='add' value='Add'>
	</form>
</body>
</html>
