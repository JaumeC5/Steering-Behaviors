#include "SteeringBehavior.h"



SteeringBehavior::SteeringBehavior()
{
}


SteeringBehavior::~SteeringBehavior()
{
}

Vector2D SteeringBehavior::KinematicSeek(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering = target - agent->position;
	steering.Normalize();
	return steering * agent->max_velocity;
}

Vector2D SteeringBehavior::KinematicSeek(Agent *agent, Agent *target, float dtime)
{
	return KinematicSeek(agent, target->position, dtime);
}

Vector2D SteeringBehavior::KinematicFlee(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering = agent->position - target;
	steering.Normalize();
	return steering * agent->max_velocity;
}

Vector2D SteeringBehavior::KinematicFlee(Agent *agent, Agent *target, float dtime)
{
	return KinematicFlee(agent, target->position, dtime);
}

/* Add here your own Steering Behavior functions definitions */

Vector2D SteeringBehavior::Seek(Agent *agent, Vector2D target, float dtime)
{
	Vector2D DesiredVelocity = target - agent->position;
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->max_velocity;
	Vector2D SteeringForce = (DesiredVelocity - agent->velocity);
	SteeringForce /= agent->max_velocity;
	return SteeringForce * agent->max_force;

	return Vector2D(0, 0);
}

Vector2D SteeringBehavior::Seek(Agent *agent, Agent *target, float dtime)
{
	return Seek(agent, target->position, dtime);
}

Vector2D SteeringBehavior::Flee(Agent *agent, Vector2D target, float dtime)
{
	Vector2D DesiredVelocity = agent->position - target;
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->max_velocity;
	Vector2D SteeringForce = (DesiredVelocity - agent->velocity);
	SteeringForce /= agent->max_velocity;
	return SteeringForce * agent->max_force;

	return Vector2D(0,0);
}

Vector2D SteeringBehavior::Flee(Agent *agent, Agent *target, float dtime)
{
	return Flee(agent, target->position, dtime);
}

Vector2D SteeringBehavior::Arrive(Agent *agent, Vector2D target, float slowingRadius, float dtime) 
{
	Vector2D distanceToTarget = target - agent->position;
	float absDistanceToTarget = abs(sqrt(distanceToTarget.x * distanceToTarget.x + distanceToTarget.y * distanceToTarget.y));
	

	float factor = absDistanceToTarget / slowingRadius;

	if (absDistanceToTarget > slowingRadius) {
		Vector2D DesiredVelocity = agent->position - target;
		DesiredVelocity.Normalize();
		DesiredVelocity *= agent->max_velocity;
		Vector2D SteeringForce = (DesiredVelocity - agent->velocity);
		SteeringForce /= agent->max_velocity;
		return SteeringForce * agent->max_force;
	}
	else {
		Vector2D DesiredVelocity = agent->position - target;
		DesiredVelocity.Normalize();
		DesiredVelocity *= factor;
		Vector2D SteeringForce = (DesiredVelocity - agent->velocity);
		SteeringForce /= factor;
		return SteeringForce * agent->max_force;
	}

}
Vector2D SteeringBehavior::Arrive(Agent *agent, Agent *target, float dtime) 
{
	return Arrive(agent, target, dtime);
}