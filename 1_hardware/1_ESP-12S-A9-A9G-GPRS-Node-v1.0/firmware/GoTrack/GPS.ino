// Keep the current position, speed, course and time updated
class GPSTask : public Task
{
  protected:
    void setup()
    {

    }

    void loop()
    {
      delay(1000);
    }

  private:
    uint8_t state;
} gps_task;
