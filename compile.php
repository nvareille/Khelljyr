<?php
function recursive_str_replace($replacethis,$withthis,$inthis)
  {
  	$inthis = str_replace($replacethis,$withthis,$inthis);
  	if(stristr($inthis,$replacethis)!==FALSE)
    	return recursive_str_replace($replacethis,$withthis,$inthis);
  	return $inthis;
  }

function get_files_to_compile($path)
{
	$f = array();

	$files = scandir($path);
	foreach ($files as $file)
	{
		if ($file == "." || $file == "..")
			continue;

		$file = $path . '/' . $file;
		if (substr($file, strrpos($file, '.') + 1) == 'c')
		{
			$f[] = $file;
		}
		elseif (is_dir($file))
		{
			$f = array_merge(get_files_to_compile($file), $f);
		}
	}
	return ($f);
}

function clean_code($str)
{
	$str = str_replace("(return )", "return ", $str);
	return ($str);
}

function trim_line($str)
{
	$str = recursive_str_replace("\t", ' ', $str);
	$str = recursive_str_replace('  ', ' ', $str);
	$str = recursive_str_replace('static ', '', $str);
	return ($str);
}

function treat_line($str, $name, &$fcts)
{
	$arr = array();

	//type fct(args)
	if (preg_match("/^([a-z,A-Z,_,0-9]*) ([a-z,A-Z,_,0-9]*)(\(.*\))$/", $str, $arr))
	{
		if ($arr[2] == 'main')
			return ($arr[1] . ' ' . '(' . $arr[2] . ')' . $arr[3] . "\n");
		else
		{
			$fcts["($arr[2])"] = '(' . $name . $arr[2] . ')';
			return ('static ' . $arr[1] . ' ' . '(' . $name . $arr[2] . ')' . $arr[3] . "\n");
		}
	}

	//type var = fct(args)
	if (preg_match("/^(.*) (.*) = (.*)(\(.*\));$/", $str, $arr))
	{
		$v = str_replace(' ', '', $arr[4]);
		if (strlen($v) > 2)
		{
			$v = str_replace('(', '((', $v);
			$v = str_replace(')', '))', $v);
			$v = explode(',', $v);
			$v = implode('),(', $v);
		}
		return ($arr[1] . ' ' . $arr[2] . ' = (' . $arr[3] . ')' . $v . ';' . "\n");
	}

	//var = fct(args)
	if (preg_match("/^(.*) = (.*)(\(.*\));$/", $str, $arr))
	{
		$v = str_replace(' ', '', $arr[3]);
		if (strlen($v) > 2)
		{
			$v = str_replace('(', '((', $v);
			$v = str_replace(')', '))', $v);
			$v = explode(',', $v);
			$v = implode('),(', $v);
		}
		return ($arr[1] . ' = (' . $arr[2] . ')' . $v . ';' . "\n");
	}

	//fct(args)
	if (preg_match("/^(.*)(\(.*\));$/", $str, $arr))
	{
		$v = str_replace(' ', '', $arr[2]);
		if (strlen($v) > 2)
		{
			$v = str_replace('(', '((', $v);
			$v = str_replace(')', '))', $v);
			$v = explode(',', $v);
			$v = implode('),(', $v);
		}
		return ('(' . $arr[1] . ')' . $v . ";\n");
	}
	return ($str . "\n");
}

function format_file_name($name)
{
	$name = str_replace('/', '_', $name);
	$name = str_replace('.', '_', $name);
	return ($name . '_');
}

function get_functions($file, &$fcts)
{
	$arr = file($file);
	$str = '';

	foreach ($arr as $line)
	{
		$str .= clean_code(treat_line(trim(trim_line($line)), format_file_name($file), $fcts));
	}

	return ($str);
}

$files = get_files_to_compile('sources');
$text = '';
$fcts = array();

foreach ($files as $file)
{
	$text .= get_functions($file, $fcts);
}

foreach ($fcts as $key => $f)
{
	$text = str_replace($key, $f, $text);
}

echo $text;
?>