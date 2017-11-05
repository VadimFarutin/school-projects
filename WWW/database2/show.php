<!DOCTYPE html>
<html>
<head>
	<title>Show</title>
	<meta charset='utf-8'>
	<link rel='shortcut icon' href='/icon.png' type='image/gif' />
	<style>
		table {
		  font-family: "Trebuchet MS",Arial,Helvetica,sans-serif;
		  min-width: 30em;
		/* width: 100%; */
		  border-collapse: collapse;
		}
		table tbody tr td {
		  white-space: nowrap;
		}
		table th {
		  font-size: 1.4em;
		  text-align: left;
		  padding-top: 5px;
		  padding-bottom: 4px;
		  background-color: #A7C942;
		  color: #FFF;
		}
		table td, table th {
		  font-size: 1.2em;
		  border: 1px solid #98BF21;
		  padding: 3px 7px 2px;
		  text-align: center;
		}
		table tr.alt td {
		  color: #000;
		  background-color: #EAF2D3;
		}
	</style>
</head>
<body>
	<pre>
	<?php
	$link = mysqli_connect('localhost', 'root', '', 'cl11125');

	if (!$link || !mysqli_set_charset($link, 'utf8')) {
		$err_no = mysqli_connect_errno($link);
		$err = mysqli_connect_error($link);
		die("Connection error ($err_no) $err\n");
	//  print("Error\n");
	}

	print('<table>');
	print('<thead><tr>');
	$r = mysqli_query($link, "DESCRIBE students");
	if ($r === FALSE) {
		die('Could not query table headers: ' . mysqli_error($link));
	}
	while ($row = mysqli_fetch_assoc($r)) {
		print("<th>${row['Field']}</th>");
	}
	mysqli_free_result($r);
	print('</tr></thead>');

	$r = mysqli_query($link, "SELECT * FROM students");
	if ($r === FALSE) {
		die('Could not query table rows: ' . mysqli_error($link));
	}

	$cnt = 0;
	while ($row = mysqli_fetch_assoc($r)) {
		$c = $cnt++ % 2 == 0 ? " class='alt'" : "";
		print("<tr$c>");
		foreach ($row as $value) {
			print("<td>$value</td>");
		}
		print("</tr>\n");
	}
	print('</table>');
	mysqli_free_result($r);
	mysqli_close($link);
	?>
	</pre>
</body>
</html>