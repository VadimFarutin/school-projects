<?php
	function load_database()
	{
		$f = fopen('database', 'r');
		$data = array();
		while (!feof($f))
		{
			$new_element = array();
			$new_element['name'] = fgets($f);
			if ($new_element['name'] != '')
			{
				$new_element['surname'] = fgets($f);
				$new_element['age'] = fgets($f);
				$new_element['height'] = fgets($f);
				$data[] = $new_element;
			}
		}
		fclose($f);
		return $data;
	}
	function search($key, $value)
	{
		$data = load_database();
		print_r($data);
		for ($i = 0; $i < count($data); $i++)
			if ($data[$i]['name'] == $value)
				print_r($data[$i]);		
	}
?>
<!DOCTYPE HTML>
<html>
<head>
	<title>Search</title>
	<meta charset='utf-8'>
</head>
<body>		
	<pre style='background-color: #DDD'>
	</pre>
	<form action='' method='post' type='submit'>
		<input type='text' name='key' value='-'>
		<input type='submit' name='search' value='Search'>
	</form>
<?php
	if (array_key_exists('submit', $_POST))
		search('name', $_POST['submit']);
?>
</body>
</html>
