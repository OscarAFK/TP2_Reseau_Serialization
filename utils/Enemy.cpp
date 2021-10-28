#include "Enemy.h"


Enemy::Enemy(Vector3 position, Quaternion rotation, int vie, typeEnemy tEnemy) :
	NetworkObject(ClassID::Enemy), m_position(position), m_rotation(rotation), m_vie(vie), m_tEnemy(tEnemy){}

void Enemy::Print() {
	std::string stringType = m_tEnemy == typeEnemy::Sbire ? "Sbire" : "Boss";
	std::cout << "---Enemy summary---\n\nType: " << stringType
		<< "\nPosition: (" << m_position.x << ", " << m_position.y << ", " << m_position.z << ")\n"
		<< "Rotation: (" << m_rotation.x << ", " << m_rotation.y << ", " << m_rotation.z << ", " << m_rotation.w << ")\n"
		<< "Vie: " << m_vie << std::endl;
}

void Enemy::Write(Serializer* s)
{
	Compressor comp;

	Vector3_32 posComp = comp.compressVector3_32(m_position, -500, 500, -500,500,0,100 , 4);
	s->Serialize(posComp.x);
	s->Serialize(posComp.y);
	s->Serialize(posComp.z);

	Quaternion_16 quatComp = comp.compressQuaternions(m_rotation);
	s->Serialize(quatComp.x);
	s->Serialize(quatComp.y);
	s->Serialize(quatComp.z);

	uint16_t vieComp = comp.compressInt(m_vie, 0, 1000);
	s->Serialize(vieComp);


	//J'ai fait �a sans trop r�fl�chir, � revoir
	/*uint8_t tEnemyComp = comp.compressInt(static_cast<uint8_t>(m_tEnemy), 0x00, 0x01);
	s->Serialize(tEnemyComp);*/
}

void Enemy::Read(Deserializer *d)
{
	Compressor comp;

	
	uint32_t posXComp = d->Read<uint32_t>();
	uint32_t posYComp = d->Read<uint32_t>();
	uint32_t posZComp = d->Read<uint32_t>();
	Vector3_32 posComp = Vector3_32(posXComp, posYComp, posZComp);
	m_position = comp.decompressVector3_32(posComp, -500, 500, -500, 500, 0, 100, 4);
	
	uint16_t rotXComp = d->Read<uint16_t>();
	uint16_t rotYComp = d->Read<uint16_t>();
	uint16_t rotZComp = d->Read<uint16_t>();
	Quaternion_16 rotComp = Quaternion_16(rotXComp, rotYComp, rotZComp);
	m_rotation = comp.decompressQuaternions(rotComp);

	uint16_t vieComp = d->Read<uint16_t>();
	m_vie = comp.decompressInt(vieComp, 0, 1000);
}
