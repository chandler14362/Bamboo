package bamboo;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

/**
 * Created by stowellc17 on 9/9/15.
 */
public class ModuleTest {

    @Test
    public void testReadDCFile() {
        Module module = Module.readDCFile(getClass().getResource("test_dc.dc").getPath());
        assertEquals(module.calculateHash(), 2);
    }

}
