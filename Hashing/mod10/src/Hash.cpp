#include <exception>
#include <algorithm>

#include "Hash.hpp"



Hash::Hash(std::initializer_list<int> init_list)
{
	std::for_each(init_list.begin(), init_list.end(), [&](int item) { insert(item); });
}

void Hash::insert(int item)
{
	int position = hash(item);

	std::shared_ptr<Node> curr{m_table[position]};

	if (curr)
	{
		while (curr->next && curr->data() < item)
			curr = curr->next;

		if (curr->data() > item)
		{
			int t = curr->data();
			curr->data() = item;
			curr->next = std::make_shared<Node>(t);
		}
		else
		{
			curr->next = std::make_shared<Node>(item);
		}
	}
	else
	{
		m_table[position] = std::make_shared<Node>(item);
	}
}

int* Hash::find(int item)
{
	int position = hash(item);

	if (!m_table[position])
		return nullptr;

	std::shared_ptr<Node> curr{ m_table[position] };

	while (curr)
	{
		if (curr->data() == item)
			return &curr->data();

		curr = curr->next;
	}

	return nullptr;
}



int Hash::hash(int key)
{
	return key % 10;
}