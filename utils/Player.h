#pragma once
#include <framework.h>
#include <Serializer.h>
#include <Deserializer.h>

namespace uqac {
	namespace serialization {
		class Player {
		public:

			Player(Vector3 position, Vector3 taille, Quaternion rotation, int vie, int armure, float argent, char nom[128]);

			void Print();
			void Write(Serializer* s);
			void Read(Deserializer* d);

		private:
			Vector3 m_position;
			Vector3 m_taille;
			Quaternion m_rotation;
			int m_vie;
			int m_armure;
			float m_argent;
			char m_nom[128];


		};
	}
}