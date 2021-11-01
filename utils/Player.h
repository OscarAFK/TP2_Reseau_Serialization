#pragma once
#include <framework.h>
#include <Serializer.h>
#include <Deserializer.h>

namespace uqac {
	namespace utilsTP2 {
		class Player {
		public:

			Player(utils::Vector3 position, utils::Vector3 taille, utils::Quaternion rotation, int vie, int armure, float argent, char nom[128]);

			void Print();
			void Write(serialization::Serializer* s);
			void Read(serialization::Deserializer* d);

		private:
			utils::Vector3 m_position;
			utils::Vector3 m_taille;
			utils::Quaternion m_rotation;
			int m_vie;
			int m_armure;
			float m_argent;
			char m_nom[128];


		};
	}
}