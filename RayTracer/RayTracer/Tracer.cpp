#include "Tracer.h"

Tracer::Tracer()
{
	mat = new Material(Material::Type::MATTE, vec3{ 1.f, 0.f, 1.f }, 1.f);

	scene.push_back(new Sphere( {0.f, 0.f, 2.f}, 1.f, mat ));
	/*scene.push_back({ {0.f, 0.f, 2.f}, 1.f });
	scene.push_back({ {0.f, 0.f, 5.f}, 0.5f });
	scene.push_back({ {-0.5f, -0.5f, 1.f}, 0.2f });
	scene.push_back({ {1.f, 1.f, 4.f}, 1.f });
	scene.push_back({ {0.f, 0.f, 2.f}, 1.f });*/
}

Tracer::~Tracer()
{
	for (Primitive* primitive : scene)
		delete primitive;
}

// renvoie la couleur intersectée par le rayon
	// cette fois-ci méthode de Whitted (recursive ray tracing)
vec3 Tracer::trace(const Ray& ray, int depth)
{
	// calcul de la couleur du background pour le pixel (i, j)
	color col = background.Get(ray.getDirection());

	if (depth >= MAX_DEPTH)
		return col;

	//Intersection intersection { FLT_MAX, nullptr};
	Intersection intersection{ std::numeric_limits<float>::max(), nullptr };

	// on itère sur l'ensemble des primitives de la scène
	for (const Primitive* primitive : scene) //c++11 ranged-for
	{
		float distanceTmp = primitive->intersect(ray);

		if (distanceTmp > EPSILON && distanceTmp < intersection.distance)
		{
			intersection.distance = distanceTmp;
			intersection.primitive = primitive;
			col = { 1.f, 0.f, 1.f };
			//col = static_cast<const Sphere*>(primitive)->GetMaterial()->GetColor();
		}
	}

	if (intersection.primitive != nullptr)
	{
		// 1. calcul du point d'intersection
		vec3 position = ray.evaluate(intersection.distance);

		// 2. calcul d'une normale (sphere)
		vec3 normal = intersection.primitive->calcNormal(position);
		//			  (position - dynamic_cast<const Sphere*>(intersection.primitive->position)).normalize();
		
		// 3. exo2 shadow feeler
		//		=> voir Light.h

		// 4. init. du nouveau rayon
		Ray newRay = Ray(normal, 0.1f, position + normal * EPSILON, 0.9f);
		// éviter les problèmes d'arrondis en ajoutant "normal * EPSILON"



		//appel récursif de trace()
		col = col * trace(newRay, depth + 1);
	}

	return col;
}
