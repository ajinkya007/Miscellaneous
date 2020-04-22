import org.springframework.boot.ExitCodeEvent;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ImportResource;
import org.springframework.context.event.EventListener;

@SpringBootApplication
@ImportResource("log_reader.xml")
public class SpringBootExitCode {

	@Bean
	MyBean myBean() {
		return new MyBean();
	}

	public static ApplicationContext context;

	public static void main(String[] args) {
		context = SpringApplication.run(LoggerUtilApplication.class, args);
	}

	private static class MyBean {

		@EventListener
		public void exitEvent(ExitCodeEvent event) {
			System.out.println("-- ExitCodeEvent --");
			System.out.println("exit code: " + event.getExitCode());
		}
	}

	public static void initiateShutdown(int returnCode) {
		SpringApplication.exit(context, () -> returnCode);
	}

	private static class MyException extends RuntimeException {

		public MyException(String message) {
			super(message);
		}

	}

}
