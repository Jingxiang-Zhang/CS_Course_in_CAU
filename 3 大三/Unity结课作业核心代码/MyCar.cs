using System;
using UnityEngine;

namespace UnityStandardAssets.Vehicles.Car
{
    [RequireComponent(typeof(CarController))]
    public class MyCar : MonoBehaviour
    {
        private CarController m_Car; // the car controller we want to use

        Vector3[] location=new Vector3[4];

        public GameObject Car;
        public GameObject Fireworks;
        private void Awake()
        {
            // get the car controller
            m_Car = GetComponent<CarController>();
            location[0] = new Vector3(110, 0, 170);
            location[1] = new Vector3(420, 0, 100);
            location[2] = new Vector3(410, 0, 400);
            location[3] = new Vector3(83, 0, 430);
        }
        int time = 0;
        int stage = -1;
        float turn = 0;
        public void setStart()
        {
            stage = 0;
        }
        private void Update()
        {
            /*
            float hor = 0;
            float x = Car.transform.position.x - location[stage].x;
            float z = Car.transform.position.z - location[stage].z;
            if (System.Math.Abs(x - location[stage].x) < 90 && System.Math.Abs(z - location[stage].z) < 90)
            {
                stage++;
            }
            double ang = System.Math.Atan(x / z)*180;
            if ((Car.transform.rotation.y - 1) * 360 > ang ) hor = -0.06f;
            else if ((Car.transform.rotation.y - 1) * 360 < ang ) hor = 0.06f;
            if (time % 30 == 0)
            {
                time = 0;
                Debug.Log(ang.ToString() +"  "+ hor+ "  " + (Car.transform.eulerAngles.y-180).ToString());
            }
            time++;
            if (m_Car.CurrentSpeed< 80){
                m_Car.Move(hor, 10, 0, 0);
            }
            else
            {
                m_Car.Move(hor, -10, 0, 0);
            }
            */
            if (Car.transform.position.z < 350)
            {
                Fireworks.SetActive(true);
            }
            else
            {
                Fireworks.SetActive(false);
            }
            switch (stage)
            {
                case -1:
                    break;
                case 0:
                    m_Car.Move(0, 10, 0, 0);
                    if (Car.transform.position.z < 160)
                        stage = 1;
                    break;
                case 1:
                    m_Car.Move(-0.15f, 10, 0, 0);
                    if (Car.transform.eulerAngles.y < 95) 
                        stage = 2;
                    break;
                case 2:
                    m_Car.Move(0, 10, 0, 0);
                    if (Car.transform.position.x > 370)
                        stage = 3;
                    break;
                case 3:
                    m_Car.Move(-0.15f, 10, 0, 0);
                    if (Car.transform.eulerAngles.y < 5)
                        stage = 4;
                    break;
                case 4:
                    m_Car.Move(0, 10, 0, 0);
                    if (Car.transform.position.z > 380)
                        stage = 5;  
                    break;
                case 5:
                    m_Car.Move(-0.15f, 10, 0, 0);
                    if (Car.transform.eulerAngles.y < 275 && !(Car.transform.eulerAngles.y < 5f))
                        stage = 6;
                    break;
                case 6:
                    m_Car.Move(0, 10, 0, 0);
                    if (Car.transform.position.x <120)
                        stage =7;
                    break;
                case 7:
                    m_Car.Move(-0.15f, 10, 0, 0);
                    if (Car.transform.eulerAngles.y < 185)
                        stage = 0;
                    break;
            }
            /*
            if (time % 30 == 0)
            {
                time = 0;
                Debug.Log(stage.ToString()  );
            }
            time++;*/
        }

    }
}
