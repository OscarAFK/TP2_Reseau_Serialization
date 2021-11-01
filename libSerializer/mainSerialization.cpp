#include "Player.h"
#include <vector>
#include "Serializer.h"
#include <iostream>
#include "Deserializer.h"

void main() {
	
	uqac::utilsTP2::Player p1 = uqac::utilsTP2::Player(uqac::utils::Vector3(1.0, 2.0, 3.0), uqac::utils::Vector3(4.0, 5.0, 6.0), uqac::utils::Quaternion(0.577, -0.240, 0.577, 0.526),100,50,420.69,"Charlot");
	uqac::serialization::Serializer s = uqac::serialization::Serializer();

	p1.Print();
	
	std::cout << "Writing" << std::endl;
	p1.Write(&s);
	
	std::cout << "Reading" << std::endl;
	std::vector<char> * buffer = s.getContainer();
	uqac::serialization::Deserializer d = uqac::serialization::Deserializer(buffer, buffer->size());
	p1.Read(&d);
	
	std::cout << "OK" << std::endl;

	p1.Print();
}