#ifndef H_HCSR04_H
#define H_HCSR04_H

#include "Arduino.h"

class HCSR04{
private :
	byte m_byPinEcho; /*!< Pin number to receive the echo */
	byte m_byPinTrigger; /*!< Pin number to send the trigger */
	
	/**
	 * \brief send a trigger for receive the distance between the sensor and an obstacle
	 */
	void sendTrigger();
	
public:
	/**
	 * \brief Constructor
	 * \param p_nPinTrigger is the pin number to send the trigger
	 * \param p_nPinEcho is the pin number to receive the distance
	 */
	HCSR04(byte p_byPinEcho, byte p_byPinTrigger);
	
	/**
	 * \brief compute the distance between the sensor and an obstacle
	 * \return return the distance
	 */
	float calculDistance();

 	/**
  	* \brief Enable to know if an obstacle is present
  	* \param p_sNCapture define the numbre of capture 
  	* \param p_sLimite define the limit for say if there is an obstacle
  	* \param p_sInterval interval between two calculDistance
  	* \return True if an obstacle is present otherwise False
  	*/
  	bool isObstacle(short p_sNCapture, short p_sLimite, short p_sInterval);
};
#endif
