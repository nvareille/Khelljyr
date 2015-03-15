var release = true;

var exec = {}
exec[0] = function ask_save(e)
{
    var item = e[1];
    var	success = e[2] != null ? e[2] : -1;
    var	failure = e[3] != null ? e[3] : -1;
    var	data = {};

    if (localStorage.getItem(item) === null)
	Pebble.sendAppMessage({0: failure});
    else
    {
	data = JSON.parse(localStorage.getItem(item));
	data[0] = success;
	Pebble.sendAppMessage(data);
    }
}

exec[1] = function set_save(e)
{
    var item_name = e[1];
    var field_nbr = e[2];
    var success = e[3 + field_nbr];
    var	data = {};
    var	count = 0;

    data[0] = success;
    while (count < field_nbr)
    {
	data[count + 1] = e[count + 3];
	++count;
    }
    localStorage.setItem(item_name, JSON.stringify(data));
    var_dump(data);
    Pebble.sendAppMessage(data);
}

exec[2] = function http_request(e)
{
    var req = new XMLHttpRequest();
    var success = e[2] != null ? e[2] : -1;
    var data = {};
    var rep = {};
    var count = 0;

    req.open('GET', e[1], false);
    req.send(null);
    data = JSON.parse(req.responseText);
    rep[0] = success;
    for (var key in data)
    {
	rep[1 + count] = data[key];
	++count;
    }
    Pebble.sendAppMessage(rep);
}

exec[3] = function remove_save(e)
{
    var item = e[1];
    var	success = e[2] != null ? e[2] : -1;

    localStorage.removeItem(item);
    Pebble.sendAppMessage({0: success});
}

function var_dump(item)
{
    if (!release)
	console.log(JSON.stringify(item));
}

function sendConnect(e)
{
}

function appMessageUpdate(e)
{
    if (e.payload[0] == null)
    {
	e.payload[0] = e.payload["dummy"];
	delete e.payload["dummy"]
    }
    exec[e.payload[0]](e.payload);
}

Pebble.addEventListener("ready", sendConnect);
Pebble.addEventListener("appmessage", appMessageUpdate);
