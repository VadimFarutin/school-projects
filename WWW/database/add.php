<!DOCTYPE HTML>
<html>
<head>
	<title>Add</title>
	<meta charset='utf-8'>
</head>
<body>
<?php
	function add()
	{
		$f = fopen('database', 'a');
		fprintf($f, $_POST['name'] . "\n");
		fprintf($f, $_POST['surname'] . "\n");
		fprintf($f, $_POST['age'] . "\n");
		fprintf($f, $_POST['height'] . "\n");
		fclose($f);
	}
	if (array_key_exists('name', $_POST))
		add();
?>
	<form action='' method='post' type='submit'>
		<input type='text' name='name' value='name'>
		<br><input type='text' name='surname' value='surname'>
		<br><input type='text' name='age' value='age'>
		<br><input type='text' name='height' value='height'>
		<br><input type='submit' name='add' value='Add'>
	</form>
</body>
</html>
