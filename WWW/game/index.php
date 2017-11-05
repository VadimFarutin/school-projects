<!-- 
	Tetris
	Farutin Vadim, 11-1
	2016
-->
<!DOCTYPE HTML>
<html>
<head>
	<title>Tetris</title>
	<meta charset='utf-8'>
	<link rel='shortcut icon' href='/icon.png' type='image/gif' />
	<style>

	#cells {
		margin: auto;
		border-collapse: collapse;
		border: solid 4px black;
	}
	#cellsNext {
		margin: auto;
		margin-bottom: 1cm;
		border-collapse: collapse;
		border: solid 4px black;
	}
	tbody tr td {
		border: solid 2px black;
		width: 0.75cm;
		height: 0.75cm;
	}
	div {
		text-align: center;
	}
	h3 {
		text-align: left;
		margin-left: 3cm;
		margin-top: 0.2cm;
		margin-bottom: 0.2cm;
	}
	</style>
</head>

<body>
	<div style="display: table; margin: auto">	
		<div style="display: table-row">
			<div style="display: table-cell; width: 10cm"></div>
			<div style="display: table-cell;">
				<h1>Tetris</h1>		
			</div>
			<div style="display: table-cell; width: 10cm"></div>
		</div>
		<div style="display: table-row">
			<div style="display: table-cell; width: 10cm">
				<h2 id='level'></h2>
				<h2>Score: <span id='score'></span></h2>
			</div>
			<div style="display: table-cell; width: 10cm">
				<table id='cells'>
				<thead>
				</thead>
				<tbody>
				</tbody>
				</table>
			</div>
			<div style="display: table-cell; width: 10cm">
				<table id='cellsNext'>
				<thead>
				</thead>
				<tbody>
				</tbody>
				</table>
				<h3>A - right</h3>
				<h3>D - left</h3>
				<h3>S - down</h3>
				<h3>W - rotate</h3>
			</div>
		</div>
	</div>
<script>
	CNT_H = 20;
	CNT_W = 7;
	CNT_NEXT_H = 5;
	CNT_NEXT_W = 5;
	maskSize = 4;
	currentMask = 0;
    backgroundColor = "#AAA";
	deathColor = "blue";
	pos = {x: 1, y: 0};
	isRotated = false;
	startSpeed = 500;
	speed = 500; 
	scoreValue = 0;
	levelValue = 0;
	current = undefined;
	next = undefined;
	intervalId = undefined;
	var free = new Array(CNT_W);
	var cells = document.getElementById("cells").children[1];
	var cellsNext = document.getElementById("cellsNext").children[1];
	var score = document.getElementById("score");
	var level = document.getElementById("level");
	
	function setKeyboardControl()
	{
		document.onkeypress = function(e) {
			if (e.code == "KeyS")
				update(0, 1);
			else if (e.code == "KeyW")
				rotate();
			else if (e.code == "KeyA")
				update(-1, 0);
			else if (e.code == "KeyD")
				update(1, 0);		
		}
	}
	function setScore()
	{
		var str= "";
		str += scoreValue;
		score.innerHTML = str;
	}
	function setLevel()
	{
		var str= "Level: ";
		levelValue = Math.floor(scoreValue / 100) + 1;
		str += levelValue;
		level.innerHTML = str;
		speed = startSpeed - (levelValue - 1) * 100; 
	}
	function cell(x, y)
	{
		return cells.children[y].children[x];
	}
	function cellNext(x, y)
	{
		return cellsNext.children[y].children[x];
	}
	function makeCells()
	{
		var str= "";
		for (var y = 0; y < CNT_H; y++) 
		{
			str += "<tr>";
			for (var x = 0; x < CNT_W; x++) {
				str += "<td>" + "</td>";
			}
			str += "</tr>";
		}
		cells.innerHTML = str;
		for (var y = 0; y < CNT_H; y++)
			for (var x = 0; x < CNT_W; x++)
				cell(x, y).style.backgroundColor = backgroundColor;
		for (var x = 0; x < CNT_W; x++)
		{
			free[x] = new Array(CNT_H);
			for (var y = 0; y < CNT_H; y++)
				free[x][y] = true;
		}
		str= "";
		for (var y = 0; y < CNT_NEXT_H; y++) 
		{
			str += "<tr>";
			for (var x = 0; x < CNT_NEXT_W; x++) {
				str += "<td>" + "</td>";
			}
			str += "</tr>";
		}
		cellsNext.innerHTML = str;
		for (var y = 0; y < CNT_NEXT_H; y++)
			for (var x = 0; x < CNT_NEXT_W; x++)
				cellNext(x, y).style.backgroundColor = backgroundColor;
		
	}
	function moveCells(yClear)
	{
		for (var y = yClear; y > 2; y--)
			for (var x = 0; x < CNT_W; x++)
			{
				cell(x, y).style.backgroundColor = cell(x, y - 1).style.backgroundColor;
				free[x][y] = free[x][y - 1];
			}
		for (var x = 0; x < CNT_W; x++)
		{
			cell(x, 2).style.backgroundColor = backgroundColor;
			free[x][2] = true;
		}	
	}
	function clearRows()
	{
		for (var y = 2; y < CNT_H; y++)
		{
			isFull = true;
			for (var x = 0; x < CNT_W; x++)
				if (free[x][y] == true)
					isFull = false;
			if (isFull)
			{
				for (var x = 0; x < CNT_W; x++)
				{
					free[x][y] = true;
					cell(x, y).style.backgroundColor = backgroundColor;
				}
				scoreValue += CNT_W;
				setScore();
				setLevel();
				moveCells(y);
			}
		}
	}
	function getRandomInt(min, max)
	{
	  return Math.floor(Math.random() * (max - min) + min);
	}
	function chooseNext()
	{
		var nextType = getRandomInt(0, figures.length);
		next = figures[nextType];
	}
	function chooseFirst()
	{
		var firstType = getRandomInt(0, figures.length);
		current = figures[firstType];
		pos.x = 1;
		pos.y = 0;	
		intervalId = setInterval(function() {update(0, 1)}, speed);
	}
	function drawNext()
	{
		for (var x = 0; x < CNT_NEXT_W; x++)
			for (var y = 0; y < CNT_NEXT_H; y++)
				cellNext(x, y).style.backgroundColor = backgroundColor;
		drawAsNext();
	}
	function gameOver()
	{
		
	}
	function makeDeath()
	{
		draw(deathColor);
		if (pos.y != 0)
		{	
			pos.x = 1;
			pos.y = 0;
			current = next;
			currentMask = 0;
			clearInterval(intervalId);
			intervalId = setInterval(function() {update(0, 1)}, speed);
			chooseNext();
			drawNext();
			clearRows();
		}
		else
			gameOver();
	}
	function update(moveX, moveY)
	{
		if (moveCollision(moveX, moveY) == false)
		{
			draw(backgroundColor);
			pos.x += moveX;
			pos.y += moveY;
			draw(current.color);
		}	
	}	
	function draw(color)
	{
		for (var x = 0; x < maskSize; x++)
			for (var y = 0; y < maskSize; y++)
				if (current.masks[currentMask][y][x] == 1)
					if (pos.x + x < CNT_W && pos.y + y < CNT_H)
					{
						cell(pos.x + x, pos.y + y).style.backgroundColor = color;
						if (free[pos.x + x][pos.y + y] == false)
							cell(pos.x + x, pos.y + y).style.backgroundColor = deathColor;
					}						
	}
	function drawAsNext()
	{
		for (var x = 0; x < maskSize; x++)
			for (var y = 0; y < maskSize; y++)
				if (next.masks[0][y][x] == 1)
					cellNext(1 + x, 1 + y).style.backgroundColor = next.color;
	}
	function checkCollision(moveX, moveY)
	{
		var isCollide = false;
		for (var x = 0; x < maskSize; x++)
			for (var y = 0; y < maskSize; y++)
				if (current.masks[currentMask][y][x] == 1)
					if (pos.y + y + moveY >= CNT_H
					|| pos.x + x + moveX < 0 || pos.x + x + moveX >= CNT_W
					|| free[pos.x + x + moveX][pos.y + y + moveY] == false)
						isCollide = true;		
		return isCollide;
	}
	function moveCollision(moveX, moveY)
	{
		var isCollide = checkCollision(moveX, moveY);
		if (isCollide)
		{
			if (moveY > 0)
			{
				for (var x = 0; x < maskSize; x++)
					for (var y = 0; y < maskSize; y++)
						if (current.masks[currentMask][y][x] == 1)
							free[pos.x + x][pos.y + y] = false;
				makeDeath();
				return true;
			}
			else
			{
				pos.x -= moveX;
				pos.y -= moveY;
			}
		}
		return false;
	}
	function rotateCollision()
	{
		currentMask = (currentMask + 1) % current.masks.length;
		var isCollide = checkCollision(0, 0);
		if (isCollide == true)
			currentMask = (currentMask + 3) % current.masks.length;
	}
	function rotate()
	{
		draw(backgroundColor);
		rotateCollision();
		draw(current.color);
	}
	function init()
	{
		setKeyboardControl();
		setScore();
		setLevel();
		makeCells();
		chooseFirst();		
		chooseNext();	
		drawNext();
	}
	figures = 
	[
		{
			masks: [
					  [[1, 1, 1, 1],
					   [0, 0, 0, 0],
					   [0, 0, 0, 0],
					   [0, 0, 0, 0],],
					   
					  [[1, 0, 0, 0],
					   [1, 0, 0, 0],
					   [1, 0, 0, 0],
					   [1, 0, 0, 0],]					   
				   ],
			color: "limegreen"			
		},
		{
			masks: [
					   [[1, 1, 0, 0],
						[1, 1, 0, 0],
						[0, 0, 0, 0],
						[0, 0, 0, 0],]
				   ],
			color: "#F0F"			
		},
		{
			masks: [
					   [[0, 1, 1, 0],
						[1, 1, 0, 0],
						[0, 0, 0, 0],
						[0, 0, 0, 0],],
						
					   [[1, 0, 0, 0],
						[1, 1, 0, 0],
						[0, 1, 0, 0],
						[0, 0, 0, 0],],
					],
			color: "yellow"			
		},
		{
			masks: [
					   [[1, 1, 0, 0],
						[0, 1, 1, 0],
						[0, 0, 0, 0],
						[0, 0, 0, 0],],
						
					   [[0, 1, 0, 0],
						[1, 1, 0, 0],
						[1, 0, 0, 0],
						[0, 0, 0, 0],],
					],
			color: "#483D8B"			
		},
		{
			masks: [
					   [[1, 1, 1, 0],
						[0, 1, 0, 0],
						[0, 0, 0, 0],
						[0, 0, 0, 0],],
						
					   [[0, 1, 0, 0],
						[1, 1, 0, 0],
						[0, 1, 0, 0],
						[0, 0, 0, 0],],
					
					   [[0, 1, 0, 0],
						[1, 1, 1, 0],
						[0, 0, 0, 0],
						[0, 0, 0, 0],],
						
					   [[1, 0, 0, 0],
						[1, 1, 0, 0],
						[1, 0, 0, 0],
						[0, 0, 0, 0],],
					],
			color: "red"			
		},
		{
			masks: [
					   [[1, 1, 1, 0],
						[1, 0, 0, 0],
						[0, 0, 0, 0],
						[0, 0, 0, 0],],
						
					   [[1, 1, 0, 0],
						[0, 1, 0, 0],
						[0, 1, 0, 0],
						[0, 0, 0, 0],],
					
					   [[0, 0, 1, 0],
						[1, 1, 1, 0],
						[0, 0, 0, 0],
						[0, 0, 0, 0],],
						
					   [[1, 0, 0, 0],
						[1, 0, 0, 0],
						[1, 1, 0, 0],
						[0, 0, 0, 0],],
					],
			color: "orange"			
		},
		{
			masks: [
					   [[1, 1, 1, 0],
						[0, 0, 1, 0],
						[0, 0, 0, 0],
						[0, 0, 0, 0],],
						
					   [[0, 1, 0, 0],
						[0, 1, 0, 0],
						[1, 1, 0, 0],
						[0, 0, 0, 0],],
					
					   [[1, 0, 0, 0],
						[1, 1, 1, 0],
						[0, 0, 0, 0],
						[0, 0, 0, 0],],
						
					   [[1, 1, 0, 0],
						[1, 0, 0, 0],
						[1, 0, 0, 0],
						[0, 0, 0, 0],],
					],
			color: "#00FFFF"			
		}
	];
	
	init();
	
</script>

</body>
</html>
