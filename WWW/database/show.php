<!DOCTYPE HTML>
<html>
<head>
	<title>Show</title>
	<meta charset='utf-8'>
</head>
<body>
	<pre style='background-color: #DDD'>
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
	function show_database()
	{
		$data = load_database();
		print('<hr>');
		for ($i = 0; $i < count($data); $i++)
		{
			print("Name: " . $data[$i]['name'] . "\n");
			print("Surname: " . $data[$i]['surname'] . "\n");
			print("Age: " . $data[$i]['age'] . "\n");
			print("Height: " . $data[$i]['height'] . "\n");
			print('<hr>');
		}
	}
	show_database();
?>
	</pre>
</body>
</html>
