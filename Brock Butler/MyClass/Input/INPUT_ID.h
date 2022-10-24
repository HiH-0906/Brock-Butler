#pragma once

enum class INPUT_ID
{
	DECISION,
	CANCEL,
	ESCAPE,
	MAX
};

INPUT_ID begin(INPUT_ID);
INPUT_ID end(INPUT_ID);
INPUT_ID operator++(INPUT_ID& key);
INPUT_ID operator*(INPUT_ID key);
