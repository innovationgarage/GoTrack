// Keep the current battery voltage and temperature updated
class SensorsTask : public Task
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
} sensors_task;
